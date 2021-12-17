#ifndef OOP_LAB7_RECTANGLE_H
#define OOP_LAB7_RECTANGLE_H

#include "figure.h"
#include <iostream>

class rectangle : public figure {
public:
    rectangle() = default;

    rectangle(std::pair<double, double>& center, double h, double w) : figure(center), height(h), width(w) {}

    double square() override {
        return height * width;
    }

    void print() override {
        std::cout << *this;
    }

    void write_to_file(std::ofstream& out) override {
        int id = 1;
        out << "Rectangle {(" << center.first << ", " << center.second << "); "
            << "(" << center.first + width << ", " << center.second << "); "
            << "(" << center.first + width << ", " << center.second - height << "); "
            << "(" << center.first << ", " << center.second - height << ")}\n";
    }

    friend std::ostream& operator<<(std::ostream& out, rectangle& r);

private:
    double height = 0;
    double width = 0;
};

std::ostream& operator<<(std::ostream& out, rectangle& r) {
    out << "Rectangle {(" << r.center.first << ", " << r.center.second << "); "
        << "(" << r.center.first + r.width << ", " << r.center.second << "); "
        << "(" << r.center.first + r.width << ", " << r.center.second - r.height << "); "
        << "(" << r.center.first << ", " << r.center.second - r.height << ")}\n";
    return out;
}


#endif //OOP_LAB7_RECTANGLE_H

