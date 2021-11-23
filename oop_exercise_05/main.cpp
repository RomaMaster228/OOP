#include <iostream>
#include <memory> // unique_ptr
#include <algorithm> // for_each, count_if
#include <clocale>
#include "rectangle.hpp"
#include "queue.hpp"

/* Лабораторная работа 5. Выполнил Лисин Роман, группа М8О-206Б-20ю
Вариант 19: Очередь с прямоугольниками
*/

using namespace std;
using figure_type = int;

void writeMenu() {
	cout << "0\tВыход из программы\n";
	cout << "1\tЗапрос меню\n";
	cout << "2\tДобавить фигуру в очередь\n";
	cout << "3\tУдалить фигуру из очереди по номеру\n";
	cout << "4\tПечать фигур в очереди\n";
	cout << "5\tПечать количества фигур, площадь которых меньше заданной\n";
}

int main() {
	setlocale(LC_ALL, "rus");
	Queue<Rectangle<figure_type>> st;
	short command;
	bool menu = 1;
	writeMenu();
	while (menu) {
		cout << '\n';
		cout << "Введите команду: ";
		cin >> command;
		cout << '\n';
		switch (command) {
		case 0:
			menu = 0;
			break;
		case 1:
			writeMenu();
			break;
		case 2: {
			unique_ptr<Rectangle<figure_type>> rec = make_unique<Rectangle<figure_type>>();
			try {
				cin >> rec;
				st.Push(move(rec));
			}
			catch (const char* exception) {
				cerr << "ERROR: " << exception << '\n';
			}

		}
		break;
		case 3: {
			unsigned int id;
			cout << "Введите индекс элемента, который нужно удалить: ";
			cin >> id;
			cout << '\n';
			try {
				st.Remove(id);
			}
			catch (const char* exception) {
				cerr << "ERROR: " << exception << '\n';
			}

		}
		break;
		case 4:
			for_each(st.begin(), st.end(), print<figure_type>);
			break;
		case 5: {
			int max = 0;
			cout << "Введите площадь: ";
			cin >> max;
			cout << '\n';
			size_t a = count_if(st.begin(), st.end(), [max](unique_ptr<Rectangle<figure_type>>& elem) {return elem->Area() < max; });
			cout << a << '\n';
		}
		break;

		}
	}

	return 0;
}
