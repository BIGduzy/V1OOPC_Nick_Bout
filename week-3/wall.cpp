#include "Wall.hpp"
#include "drawable.hpp"

Wall::Wall(window& w, const vector& start, const vector& end, const vector& bounce, const int& toggle_interval):
    rectangle(w, start, end),
    start(start),
    toggle_interval(toggle_interval)
{
    drawable::bounce = bounce;
}

void Wall::draw() {
    // This could be done better, but the rectangle we have to use, uses lines
    rectangle::draw();

    if (filled) {
        for(int i = start.x; i < end.x; ++i) {
            for (int j = start.y; j < end.y; ++j) {
                w.draw(vector(i, j));
            }
        }
    }
}

void Wall::update() {
    toggle_time++;

    if (toggle_time > toggle_interval) {
        filled = !filled;
        toggle_time = 0;
    }
}
