#include "train_head.hpp"
#include <iostream>

train_head::train_head(window& w, int x, int y, int size):
    // Create train parts based on size
    w(w),
    x(x),
    y(y),
    // Create filled rect (size, 2/3) and move it 1 / 3 down
    base(w, x, y + size * 1 / 3, size, size * 2 / 3),
    // Create filled rect (1/3, size) and move it 2 / 3 right
    base1(w, x + size * 2 / 3, y , size * 1 / 3, size),
    // Create filled rect (1/10, 1/10) and move it 100% right and 8/10 down
    link(w, x + size, y + size * 8 / 10, size * 1 / 10, size * 1 / 10),
    // Create outlined rect (1/10 + 1, 7/30) and move it 1/10 left and 13/30 down (+1 to hide right border behind base)
    nose( w, x - size * 1 / 10, y + size * 13 / 30, x + 1, y + size * 20 / 30 ),
    // Create outlined rect (2/10, 16/30 + 1) and move it 1/10 right and 2/10 down (+1 to hide bottom border behind base)
    chimney(w, x + size * 1 / 10, y + size * 2 / 10, x + size * 3 / 10, y + size * 1 / 3 + 1),
    // Create outlined rect (4/10, 1/10) and move it 1/10 down
    chimney1(w, x, y + size * 1 / 10, x + size * 4 / 10, y + size * 2 / 10),
    // Create outlinded circle (1/10 radius) and move it 2/10 right and 100% down
    wheel(w, x + size * 2 / 10, y + size, size * 1 / 10),
    // Create outlinded circle (1/10 radius) and move it 8/10 right and 100% down
    wheel1(w, x + size * 8 / 10, y + size, size * 1 / 10),
    // Create diagonal line on nose
    nose1(w, x - size * 1 / 10, y + size, x + 1, y + size * 8 / 10),
    // Create straight line on nose
    nose2(w, x - size * 1 / 10, y + size, x + 1, y + size)
{}

void train_head::print() const {
    // Print every part of the train head
    base.print();
    base1.print();
    link.print();
    nose.print();
    chimney.print();
    chimney1.print();
    wheel.print();
    wheel1.print();
    nose1.print();
    nose2.print();
}

void train_head::moveX(int steps) {
    // Move x for self and every part
    x += steps;
    base.moveX(steps);
    base1.moveX(steps);
    link.moveX(steps);
    nose.moveX(steps);
    chimney.moveX(steps);
    chimney1.moveX(steps);
    wheel.moveX(steps);
    wheel1.moveX(steps);
    nose1.moveX(steps);
    nose2.moveX(steps);
}