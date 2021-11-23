#include <iostream>
using namespace std;

template <class T>
struct Rectangle {

    pair<T, T> point;
    T height;
    T width;

    Rectangle() : point{ 0,0 }, height(0), width(0) {}
    Rectangle(T x, T y, T h, T w) : point{ x,y } {
        if (h < 0 or w < 0) {
            throw "Ширина и высота должны быть положительными!";
        }
        height = h;
        width = w;
    }

    T Area() { 
        return height * width; 
    }
};

template <class T>
ostream& operator<< (ostream& out, const unique_ptr<Rectangle<T>>& A) {
    out << "Точки прямоугольника: " << "(" << A->point.first << ", " << A->point.second << ") "
        << "(" << A->point.first + A->width << ", " << A->point.second << ") "
        << "(" << A->point.first + A->width << ", " << A->point.second - A->height << ") "
        << "(" << A->point.first << ", " << A->point.second - A->height << ") "
        << "\n";
    return out;
}

template <class T>
istream& operator>> (istream& in, unique_ptr<Rectangle<T>>& A) {
    cout << "Введите координаты положения прямоугольника: ";
    in >> A->point.first >> A->point.second;
    cout << "Введите ширину прямоугольника: ";
    in >> A->width;
    cout << "Введите высоту прямоугольника: ";
    in >> A->height;
    if ((A->width < 0) || (A->height < 0)) {
        throw "Ширина и высота должны быть положительными!";
    }
    return in;
}

template <class T>
void print(unique_ptr<Rectangle<T>>& elem) {
    cout << elem;
}

/*2 1 2 3 4 4 3 0 4 0 
2 1 2 3 4 2 5 8 10 20 4 5 50
*/