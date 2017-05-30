#include "Vector2d.hpp"

Vector2d::Vector2d(int x, int y):
    x(x), y(y)
{}

bool Vector2d::operator==(const Vector2d& rhs) const {
    return (x == rhs.x && y == rhs.y);
}

Vector2d Vector2d::operator+() const {
    Vector2d temp = *this;
    return temp;
}

Vector2d Vector2d::operator+(const Vector2d& rhs) const {
    Vector2d temp = *this;
    return temp += rhs;
}

Vector2d& Vector2d::operator+=(const Vector2d& rhs) {
    x += rhs.x;
    y += rhs.y;
    return *this;
}

Vector2d Vector2d::operator*(const int& rhs) const {
    Vector2d temp = *this;
    temp.x *= rhs;
    temp.y *= rhs;
    return temp;
}

Vector2d operator*(const int& lhs, const Vector2d& rhs) {
    return rhs * lhs;
}

Vector2d& Vector2d::operator*=(const Vector2d& rhs) {
    x *= rhs.x;
    y *= rhs.y;
    return *this;
}

Vector2d& Vector2d::operator*=(const int& rhs) {
    x *= rhs;
    y *= rhs;
    return *this;
}