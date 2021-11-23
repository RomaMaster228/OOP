#include <iostream>
#include <clocale>
#include "Ntree.h"

/*Лабораторная работа 4, подготовил Лисин Роман, группа М8О-206Б-20
 Вариант 21: N-дерево с треугольниками
*/

int main() {
	setlocale(LC_ALL, "rus");
	int N, triangles;
	cout << "Введите количество детей у узла в N-дереве: ";
	if (!(cin >> N)) {
		cout << "Ошибка ввода N" << '\n';
		abort();
 	}
	Triangle root;
	cout << "Введите треугольник-корень N-дерева: ";
	if (!(cin >> root)) {
		cout << "Ошибка ввода треугольника" << '\n';
		abort();
	}
	cout << "Введите количество остальных треугольников в N-дереве: ";
	if (!(cin >> triangles)) {
		cout << "Ошибка ввода количество треугольников" << '\n';
		abort();
	}
	Ntree t = {root, N};
	if (triangles < 1) {
		cout << "Треугольников должно быть больше одного" << '\n';
		abort();
	}
	for (int i = 0; i < triangles; i++) {
		Triangle tr;
		if (!(cin >> tr)) {
			cout << "Ошибка ввода треугольника" << '\n';
			abort();
		}
		t.insert(tr);
	}
	cout << "Печать дерева: " << '\n';
	cout << t;
	cout << "Какой элемент дерева удалить? ";
	int pos;
	if (!(cin >> pos) || pos < 1 || pos > triangles) {
		cout << "Ошибка ввода позиции для удаления" << '\n';
		abort();
	}
	t.remove(pos);
	cout << "Печать дерева: " << '\n';
	if (t.get_root()) {
		cout << t;
	}
	cout << "Посмотрим какой у дерева корень: ";
	if (pos == 1) {
		cout << "Дерева больше нет" << '\n';
	}
	else {
		t.find(1);
	}
	return 0;
}


/*
4
1 2 3
6
4 5 6
7 8 9
10 11 12
13 14 15
16 17 18
19 20 21
1



*/