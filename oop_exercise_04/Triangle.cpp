#include "Triangle.h"
#include <iostream>
#include <cmath>

Triangle::Triangle() : Triangle(0, 0, 0) {
}

Triangle::Triangle(size_t i, size_t j, size_t k) : side_a(i), side_b(j), side_c(k) {
}

Triangle::Triangle(const Triangle& orig) {
	side_a = orig.side_a;
	side_b = orig.side_b;
	side_c = orig.side_c;
}

double Triangle::Square() {
	double p = double(side_a + side_b + side_c) / 2.0;
	return sqrt(p * (p - double(side_a)) * (p - double(side_b)) * (p - double(side_c)));
}

Triangle& Triangle::operator=(const Triangle& right) {
	if (this == &right) return *this;
	side_a = right.side_a;
	side_b = right.side_b;
	side_c = right.side_c;
	return *this;
}

Triangle& Triangle::operator++() {
	side_a++;
	side_b++;
	side_c++;
	return *this;
}

Triangle operator+(const Triangle& left, const Triangle& right) {
	return Triangle(left.side_a + right.side_a, left.side_b + right.side_b, left.side_c + right.side_c);
}

Triangle::~Triangle() {
}

std::ostream& operator<<(std::ostream& os, const Triangle& obj) {
	os << "a=" << obj.side_a << ", b=" << obj.side_b << ", c=" << obj.side_c << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Triangle& obj) {
	is >> obj.side_a;
	is >> obj.side_b;
	is >> obj.side_c;
	return is;
}
