#ifndef OOP_LAB7_RHOMBUS_H
#define OOP_LAB7_RHOMBUS_H

#include "figure.h"
#include <iostream>

class rhombus : public figure {
public:
    rhombus() = default;

    rhombus(std::pair<double, double>& center, double d1, double d2) : figure(center), diag1(d1), diag2(d2) {}

    double square() override {
        return diag1 * diag2 * 0.5;
    }

    void print() override {
        std::cout << *this;
    }

    void write_to_file(std::ofstream& out) override {
        int id = 1;
        out << "Rhombus {(" << center.first - diag1 * 0.5 << ", " << center.second << "); (";
        out << center.first << ", " << center.second + diag2 * 0.5 << "); (";
        out << center.first + diag1 * 0.5 << ", " << center.second << "); (";
        out << center.first << ", " << center.second - diag2 * 0.5 << ")}\n";
    }

    friend std::ostream& operator<<(std::ostream& out, rhombus& r);

private:
    double diag1 = 0;
    double diag2 = 0;
};

std::ostream& operator<<(std::ostream& out, rhombus& r) {
    out << "Rhombus {(" << r.center.first - r.diag1 * 0.5 << ", " << r.center.second << "); (";
    out << r.center.first << ", " << r.center.second + r.diag2 * 0.5 << "); (";
    out << r.center.first + r.diag1 * 0.5 << ", " << r.center.second << "); (";
    out << r.center.first << ", " << r.center.second - r.diag2 * 0.5 << ")}\n";
    return out;
}


#endif //OOP_LAB7_RHOMBUS_H
