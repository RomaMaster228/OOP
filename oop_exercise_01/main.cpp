#include <iostream>
#include <clocale>
using namespace std;

class Budget {

public:

	Budget(double a, double b) {
		this->a = int(a * 100 + 0.5) / 100.0;
		this->b = int(b * 100 + 0.5) / 100.0;
	}

	void print_budget() {
		cout << "Собственная часть: "<< this->a << " Заёмная часть: " << this->b << '\n';
	}

	friend Budget operator+ (const Budget& A, const Budget& B) {
		return Budget(A.a + B.a, A.b + B.b);
	}

	friend Budget operator- (const Budget& A, const Budget& B) {
		return Budget(A.a - B.a, A.b - B.b);
	}

	void multiply_own_part(double value) {
		a *= value;
	}

	void multiply_return_part(double value) {
		b *= value;
	}

	void divide_own_part(double value) {
		a /= value;
	}

	void divide_return_part(double value) {
		b /= value;
	}

	bool operator== (const Budget& B) {
		if (this->a == B.a && this->b == B.b) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator> (const Budget& B) {
		if ((this->a - this->b) > (B.a - B.b)) {  // Заёмные деньги надо отдавать
			return true;
		}
		else {
			return false;
		}
	}

	bool operator< (const Budget& B) {
		if ((this->a - this->b) < (B.a - B.b)) {  // Заёмные деньги надо отдавать
			return true;
		}
		else {
			return false;
		}
	}

private:

	double a;  // own part 
	double b;  // return part
};


int main() {
	setlocale(LC_ALL, "rus");
	double a1, b1, a2, b2;
	cout << "Введите через пробел собственные деньги и заёмные деньги одного и второго бюджетов: ";
	if (!(cin >> a1 >> b1 >> a2 >> b2)) {
		cout << "Данные некорректны!" << '\n';
		return -1;
	}
	Budget a = { a1, b1 };;
	Budget b = { a2, b2 };
	cout << "Первый бюджет: ";
	a.print_budget();
	cout << "Второй бюджет: ";
	b.print_budget();
	cout << "Сумма бюджетов: ";
	(a + b).print_budget();
	cout << "Разность бюджетов: ";
	(a - b).print_budget();
	if (a == b) {
		cout << "Бюджеты равны" << '\n';
	}
	else {
		cout << "Бюджеты не равны" << '\n';
	}
	if (a > b) {
		cout << "Первый бюджет больше" << '\n';
	}
	else {
		cout << "Второй бюджет больше" << '\n';
	}
	cout << "Умножим собственные деньги первого бюджета на 2" << '\n';
	a.multiply_own_part(2);
	a.print_budget();
	cout << "Поделим заёмные деньги первого бюджета на 5" << '\n';
	a.divide_return_part(5);
	a.print_budget();
	return 0;
}