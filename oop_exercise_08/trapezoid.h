#ifndef OOP_LAB7_TRAPEZOID_H
#define OOP_LAB7_TRAPEZOID_H

#include "figure.h"
#include <iostream>

class trapezoid : public figure {
public:
    trapezoid() = default;

    trapezoid(double a, double b, double h) : a(a), b(b), h(h) {}

    double square() override {
        return (a + b) / 2 * h;
    }

    void print() override {
        std::cout << *this;
    }

    void write_to_file(std::ofstream& out) override {
        int id = 1;
        out << "Trapezoid {(" << " Bases: " << a << ", " << b << "; Height: " << h << ")}\n";
    }

    friend std::ostream& operator<<(std::ostream& out, trapezoid& r);

private:
    double a = 0;
    double b = 0;
    double h = 0;
};

std::ostream& operator<<(std::ostream& out, trapezoid& t) {
    out << "Trapezoid {(" << " Bases: "<< t.a << ", " << t.b << "; Height: " << t.h << ")}\n";
    return out;
}


#endif //OOP_LAB7_TRAPEZOID_H
