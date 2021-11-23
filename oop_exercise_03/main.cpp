#include <iostream>
#include <vector>
#include <clocale>
#include <cmath>
using namespace std;

/*Лабораторная работа 3, подготовил Лисин Роман, группа М8О-206Б-20 
 Вариант 9: Треугольник, Квадрат, Прямоугольник
*/

struct Point {
    Point() {}
    Point(double const& x_, double const& y_) : x(x_), y(y_) {}
    double x;
    double y;
};

void print_error() {
    cout << "Данные некорректны" << '\n';
}

double distance(const Point& p1, const Point& p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

class Figure {

public:
    virtual Point center() = 0;
    virtual void print_figure() const = 0;
    virtual double area() = 0;
    virtual ~Figure() {}
};

class Triangle : public Figure {

    Point p1;
    Point p2;
    Point p3;

public:

    Triangle() {}
    Triangle(Point const& p1_, Point const& p2_, Point const& p3_) : p1(p1_), p2(p2_), p3(p3_) {}
    
    void get_coordinates(const Point& p1, const Point& p2, const Point& p3) {
        this->p1 = p1;
        this->p2 = p2;
        this->p3 = p3;
    }

    Point center() { 
        return Point((this->p1.x + this->p2.x + this->p3.x) / 3, (this->p1.y + this->p2.y + this->p3.y) / 3); 
    }

    double area() {
        double square = abs((this->p2.x - this->p1.x) * (this->p3.y - this->p1.y) - (this->p3.x - this->p1.x) * (this->p2.y - this->p1.y)) / 2;
        return square;
    }

    void print_figure() const {
        cout << '\n';
        cout << "Triangle:" << '\n';
        cout << "First point: (" << this->p1.x << "," << this->p1.y << ")" << '\n';
        cout << "Second point: (" << this->p2.x << "," << this->p2.y << ")" << '\n';
        cout << "Third point: (" << this->p3.x << "," << this->p3.y << ")" << '\n';
    }
};


class Square : public Figure {  // Квадрат задается 2 точками одной из диагоналей

    Point p1;
    Point p2;
public:

    Square() {}
    Square(Point const& p1_, Point const& p2_) : p1(p1_), p2(p2_) {}

    void get_point1(const Point& p1) { 
        this->p1 = p1; 
    }
    void get_point2(const Point& p2) {
        this->p2 = p2;
    }

    Point center() { 
        return Point((p1.x + p2.x) / 2, (p1.y + p2.y) / 2); 
    }

    double area() { 
        return (p1.x - p2.x) * (p1.x - p2.x);
    }

    void print_figure() const {
        cout << '\n';
        cout << "Square:" << '\n';
        cout << "First point: (" << this->p1.x << "," << this->p1.y << ")" << '\n';
        cout << "Second point: (" << this->p2.x << "," << this->p2.y << ")" << '\n';
    }
};

class Rectangle : public Figure {

    Point p1;
    Point p2;
    Point p3;
    Point p4;

public:

    Rectangle() {}
    Rectangle(Point const& p1_, Point const& p2_, Point const& p3_, Point const& p4_) : p1(p1_), p2(p2_), p3(p3_), p4(p4_) {}

    void get_coordinates(const Point& p1, const Point& p2, const Point& p3, Point const& p4) {
        this->p1 = p1;
        this->p2 = p2;
        this->p3 = p3;
        this->p4 = p4;
    }

    Point center() {
        return Point((this->p1.x + this->p2.x + this->p3.x + this->p4.x) / 4, (this->p1.y + this->p2.y + this->p3.y + this->p4.y) / 4);
    }

    double area() {
        double a = distance(this->p1, this->p2);
        double b = distance(this->p2, this->p3);
        double c = distance(this->p3, this->p4);
        double d = distance(this->p4, this->p1);
        double p = (a + b + c + d) / 2;
        return sqrt(abs(p - a) * abs(p - b) * abs(p - c) * abs(p - d));
    }

    void print_figure() const {
        cout << '\n';
        cout << "Rectangle:" << '\n';
        cout << "First point: (" << this->p1.x << "," << this->p1.y << ")" << '\n';
        cout << "Second point: (" << this->p2.x << "," << this->p2.y << ")" << '\n';
        cout << "Third point: (" << this->p3.x << "," << this->p3.y << ")" << '\n';
        cout << "Fourth point: (" << this->p4.x << "," << this->p4.y << ")" << '\n';
    }
};


istream& operator>> (istream& is, Square& sqr) {
    double x1, y1, x2, y2;
    if (!(is >> x1 >> y1 >> x2 >> y2)) {
        print_error();
        abort;
    }
    Point p1(x1, y1); Point p2(x2, y2);
    sqr.get_point1(p1); sqr.get_point2(p2);
    return is;
}

istream& operator>> (istream& is, Triangle& tri) {
    double x1, y1, x2, y2, x3, y3;
    if (!(is >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)) {
        print_error();
        abort;
    }
    Point p1(x1, y1); Point p2(x2, y2); Point p3(x3, y3);
    tri.get_coordinates(p1, p2, p3);
    return is;
}

istream& operator>> (istream& is, Rectangle& rec) {
    double x1, y1, x2, y2, x3, y3, x4, y4;
    if (!(is >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4)) {
        print_error();
        abort;
    }
    Point p1(x1, y1); Point p2(x2, y2); Point p3(x3, y3); Point p4(x4, y4);
    if ((distance(p1, p2) != distance(p3, p4)) || (distance(p2, p3) != distance(p4, p1))) {
        print_error();
        abort;
    }
    rec.get_coordinates(p1, p2, p3, p4);
    return is;
}

double area_in_vector(std::vector<Figure*> figures) {  // Сумма площадей фигур в векторе
    double sum = 0; 
    vector<Figure*>::iterator iter = figures.begin();
    while (iter != figures.end()) {
        sum += (*iter)->area();
        iter++;
    }
    return sum;
}

void delete_el(vector<Figure*>& figures, int i = 0) {
    figures.erase(figures.begin() + i);
}

int main() {
    setlocale(LC_ALL, "rus");
    vector<Figure*> figures;
    cout << "Введите 4 точки прямоугольника в порядке обхода в формате x1 y1: " << '\n';
    Rectangle r;
    if (!(cin >> r)) {
        return 1;
    }
    cout << "Введите 2 точки диагонали квадрата в формате x1 y1: " << '\n';
    Square s;
    if (!(cin >> s)) {
        return 1;
    }
    cout << "Введите 3 точки треугольника в порядке обхода в формате x1 y1: " << '\n';
    Triangle t;
    if (!(cin >> t)) {
        return 1;
    }
    if (r.area() <= 0 || s.area() <= 0 || t.area() <= 0) {  // проверка на корректность фигуры
        print_error();
        return 1;
    }
    figures.push_back(&r);
    figures.push_back(&t);
    figures.push_back(&s);
    cout << "Фигуры в векторе: " << '\n';
    vector<Figure*>::iterator iter = figures.begin();
    while (iter != figures.end()) {
        (*iter)->print_figure();
        cout << "Площадь = " << (*iter)->area() << '\n';
        cout << "Центр x = " << (*iter)->center().x << ", y = " << (*iter)->center().y << '\n';
        ++iter;
    }
    cout << "\n\nСумма всех площадей в векторе: " << area_in_vector(figures) << '\n';
    cout << "Удаляем элемент с индексом 0" << '\n';
    //удаляем элемент с индексом 0
    delete_el(figures, 0);
    iter = figures.begin();
    while (iter != figures.end()) {
        (*iter)->print_figure();
        cout << "Площадь = " << (*iter)->area() << '\n';
        cout << "Центр x = " << (*iter)->center().x << ", y = " << (*iter)->center().y << '\n';
        ++iter;
    }
    cout << "Сумма всех площадей в векторе после удаления первого элемента: " << area_in_vector(figures) << '\n';
    return 0;
}