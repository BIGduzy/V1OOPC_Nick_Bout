#include "filled_rectangle.hpp"

filled_rectangle::filled_rectangle(window& w, int x, int y, int width, int height):
    w(w),
    x(x),
    y(y),
    width(width),
    height(height)
{}

void filled_rectangle::print() const {    
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            w.draw(i + x, j + y);
        }
    }
}
