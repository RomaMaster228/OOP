#include <iostream>
#include <clocale>
#include <string>
using namespace std;

/* Лабораторная работа 2, подготовил Лисин Роман, группа М8О-206Б-20
Вариант 16: Создать класс Position для работы с географическими координатами. Координаты задаются двумя числами широта и долгота. 
Долгота находится в диапазоне от -180 до 180 градусов. Широта находится в диапазоне от -90 до 90 градусов. 
Реализовать арифметические операции сложения, вычитания, умножения и деления, а также операции сравнения*/

class Position {

public:

    Position(int latitude, int longitude) {
        this->latitude = latitude % 91;
        this->longitude = longitude % 181;
    }

    Position operator+ (const Position& B) {
        return Position(this->latitude + B.latitude, this->longitude + B.longitude);
    }

    Position operator- (const Position& B) {
        return Position(this->latitude - B.latitude, this->longitude - B.longitude);
    }

    Position operator* (const Position& B) {
        return Position(this->latitude * B.latitude, this->longitude * B.longitude);
    }

    Position operator/ (const Position& B) {
        return Position(this->latitude / B.latitude, this->longitude / B.longitude);
    }

    bool operator== (const Position& B) {
        if (this->latitude == B.latitude && (this->longitude == B.longitude 
            || (abs(this->longitude) == 180 && abs(B.longitude) == 180)) ) {
            return true;
        }
        else {
            return false;
        }
    }

    void print_position() const {
        cout << "Широта:  " << this->latitude << "  ";
        cout.fill(0);
        cout << "Долгота: " << this->longitude << '\n';
        cout.fill(0);
    }

    friend ostream& operator<< (ostream& out, const Position& position);
    friend istream& operator>> (istream& in, Position& position);

private:
    int latitude;
    int longitude;
};

ostream& operator<< (ostream& out, const Position& pos) {
    out << "Широта: " << pos.latitude << "  Долгота: " << pos.longitude << '\n';
    return out;
}

istream& operator>> (istream& in, Position& pos) {
    int lat1, long1;
    in >> lat1 >> long1;
    return in;
}

const Position operator "" _position(const char* t, size_t size) {
    string lat = "";
    string longi = "";
    bool flag = false;
    for (int i = 0; i < size; i++) {
        if (t[i] == '.') {
            flag = true;
        }
        else if (!flag) {
            lat += t[i];
        }
        else {
            longi += t[i];
        }
    }
    return Position(stoi(lat), stoi(longi));
}

int main() {
    setlocale(LC_ALL, "rus");
    cout << "Введите широту и долготу первой и второй позиций: ";
    int lat1, long1, lat2, long2;
    // cin >> pos;
    if (!(cin >> lat1 >> long1 >> lat2 >> long2)) {
        cout << "Данные некорректны!" << '\n';
        return -1;
    }
    
    Position first = { lat1, long1 };
    Position second = { lat2, long2 };
    cout << "Первая позиция:  " << '\n';
    first.print_position();
    cout << "Вторая позиция:  " << '\n';
    second.print_position();
    cout << "Сумма позиций:  " << '\n';
    (first + second).print_position();
    cout << "Разность позиций:  " << '\n';
    (first - second).print_position();
    cout << "Умножение позиций:  " << '\n';
    (first * second).print_position();
    cout << "Деление первой позицию на вторую:  " << '\n';
    (first / second).print_position();
    if (first == second) {
        cout << "Позиции равны" << '\n';
    }
    else {
        cout << "Позиции не равны" << '\n';
    }
    const Position pos = "-12.-34"_position;
    cout << "Константная позиция -12.-34_position: " << '\n';
    pos.print_position();
    // cout << pos;
    return 0;
}