#include "vector.hpp"

Vector::Vector():
    x(0), y(0)
{}
Vector::Vector(int x, int y):
    x(x), y(y)
{}

bool Vector::operator==(const Vector& rhs) const {
    return (x == rhs.x && y == rhs.y);
}

Vector Vector::operator+() const {
    Vector temp(x, y);
    return temp;
}

Vector Vector::operator+(const Vector& rhs) const {
    Vector temp(x, y);
    return temp += rhs;
}

Vector& Vector::operator+=(const Vector& rhs) {
    x += rhs.x;
    y += rhs.y;
    return *this;
}

Vector Vector::operator*(const int& rhs) const {
    Vector temp(x, y);
    temp.x *= rhs;
    temp.y *= rhs;
    return temp;
}

Vector operator*(const int& lhs, const Vector& rhs) {
    return rhs * lhs;
}

Vector& Vector::operator*=(const Vector& rhs) {
    x *= rhs.x;
    y *= rhs.y;
    return *this;
}

Vector& Vector::operator*=(const int& rhs) {
    x *= rhs;
    y *= rhs;
    return *this;
}

std::ostream& operator<<( std::ostream& lhs, const Vector& rhs ){
    return lhs << "(" << rhs.x << ", " << rhs.y << ")";
}