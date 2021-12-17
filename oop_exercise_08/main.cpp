#include <iostream>
#include <queue>
#include <ctime>
#include <sstream>

#include "factory.h"
#include "server.hpp"

/* Лабораторная работа №8
Вариант 27: Прямоугольник, трапеция, ромб
Выполнил Лисин Роман, группа М8О-206Б-20
*/

void print_menu() {
	std::cout << "1. Add rhombus" << std::endl;
	std::cout << "2. Add rectangle" << std::endl;
	std::cout << "3. Add trapezoid" << std::endl;
	std::cout << "0. Exit" << std::endl << std::endl;
}

using server_t = server<std::shared_ptr<figure>>;

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cout << "Syntax: ./oop_exercise_08 buffer_size" << std::endl;
		return 1;
	}

	if (std::stoi(argv[1]) <= 0) {
		std::cout << "Incorrect buffer size" << std::endl;
		return 2;
	}

	size_t buf_size = std::stoul(argv[1]);

	// adding subscribers (handler functions)
	server_t::get().register_subscriber([](const std::shared_ptr<figure> fig) {
		fig->print();
		});

	server_t::get().register_subscriber([](const std::shared_ptr<figure> fig) {
		fig->write_to_file(server_t::get().get_fd());
		});

	// starting handler
	std::thread th([buf_size]() {
		server_t::get().run(buf_size);
		});

	print_menu();

	int cmd;
	while (true) {
		std::cin >> cmd;
		if (cmd == 1) {
			std::cout << "Enter coords of the center and lengths of diagonals" << std::endl;
			std::shared_ptr<figure> fig = factory::create((figure_type)cmd);
			server_t::get().publish(fig);
			std::cout << "Successfully added" << std::endl;
		}
		else if (cmd == 2) {
			std::cout << "Enter coords of the left highest point, the lengths of height and width" << std::endl;
			std::shared_ptr<figure> fig = factory::create((figure_type)cmd);
			server_t::get().publish(fig);
			std::cout << "Successfully added" << std::endl;
		}
		else if (cmd == 3) {
			std::cout << "Enter the lengths of bases and height" << std::endl;
			std::shared_ptr<figure> fig = factory::create((figure_type)cmd);
			server_t::get().publish(fig);
			std::cout << "Successfully added" << std::endl;
		}
		else if (cmd == 0) {
			server_t::get().stop();
			break;
		}
		else {
			std::cout << "Incorrect cmd" << std::endl;
		}
	}

	th.join();
}