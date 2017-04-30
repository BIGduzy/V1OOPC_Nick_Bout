#include "train_butt.hpp"

train_butt::train_butt(window& w, int x, int y, int size):
    // Create train parts based on size
    w(w),
    x(x),
    y(y),
    // Create filled rect (8/10, 7/10) and move it 1/10 right and 3/10 down
    body(w, x + size * 1 / 10, y + size * 3 / 10, size * 8 / 10, size * 7 / 10),
    // Create filled rect (size, 2/10) and move it 1/10 down
    roof(w, x, y + size * 1 / 10, size, size * 2 / 10),
    // Create filled rect (2/10, 1/10) and move it 1/10 left and 8/10 down
    link(w, x - size * 1 / 10, y + size * 8 / 10, size + size * 2 / 10, size * 1 / 10),
    // Create outlined circle (1/10 radius) and move it 3/10 right and 100% down
    wheel(w, x + size * 3 / 10, y + size, size * 1 / 10),
    // Create outlined circle (1/10 radius) and move it 8/10 right and 100% down
    wheel1(w, x + size * 8 / 10, y + size, size * 1 / 10)
{}

void train_butt::print() const {
    // Print every part of the train butt
    body.print();
    roof.print();
    link.print();
    wheel.print();
    wheel1.print();
}

void train_butt::moveX(int steps) {
    // Move x for self and every part
    x += steps;
    body.moveX(steps);
    roof.moveX(steps);
    link.moveX(steps);
    wheel.moveX(steps);
    wheel1.moveX(steps);
}