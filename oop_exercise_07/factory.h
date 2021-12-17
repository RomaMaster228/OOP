#ifndef OOP_LAB7_FACTORY_H
#define OOP_LAB7_FACTORY_H

#include "rhombus.h"
#include "rectangle.h"
#include "trapezoid.h"

enum class figure_type {
    rhombus = 1,
    rectangle = 2,
    trapezoid = 3
};

struct factory {
    static std::shared_ptr<figure> create(figure_type t) {
        switch (t) {
        case figure_type::rhombus: {
            std::pair<double, double> center;
            double d1, d2;
            std::cin >> center.first >> center.second >> d1 >> d2;
            return std::make_shared<rhombus>(center, d1, d2);
        }
        case figure_type::rectangle: {
            std::pair<double, double> center;
            double h, w;
            std::cin >> center.first >> center.second >> h >> w;
            return std::make_shared<rectangle>(center, h, w);
        }
        case figure_type::trapezoid: {
            std::pair<double, double> center;
            double a, b, h;
            std::cin >> a >> b >> h;
            return std::make_shared<trapezoid>(a, b, h);
        }
        default:
            throw std::logic_error("Wrong figure id");
        }
    }

    static std::shared_ptr<figure> read_from_file(figure_type t, std::ifstream& in) {
        switch (t) {
        case figure_type::rhombus: {
            std::pair<double, double> center;
            double d1, d2;
            in.read((char*)&center.first, sizeof(double));
            in.read((char*)&center.second, sizeof(double));
            in.read((char*)&d1, sizeof(double));
            in.read((char*)&d2, sizeof(double));
            return std::make_shared<rhombus>(center, d1, d2);
        }
        case figure_type::rectangle: {
            std::pair<double, double> center;
            double height, width;
            in.read((char*)&center.first, sizeof(double));
            in.read((char*)&center.second, sizeof(double));
            in.read((char*)&height, sizeof(double));
            in.read((char*)&width, sizeof(double));
            return std::make_shared<rectangle>(center, height, width);
        }
        case figure_type::trapezoid: {
            double a, b, h;
            in.read((char*)&a, sizeof(double));
            in.read((char*)&b, sizeof(double));
            in.read((char*)&h, sizeof(double));
            return std::make_shared<trapezoid>(a, b, h);
        }
        default:
            throw std::logic_error("Wrong figure id");
        }
    }
};


#endif //OOP_LAB7_FACTORY_H
