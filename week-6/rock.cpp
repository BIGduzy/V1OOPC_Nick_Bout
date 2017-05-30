#include "Rock.hpp"

Rock::Rock(hwlib::glcd_oled& display, Vector2d position, Vector2d size, Vector2d velocity):
    Object(display, position, size, velocity)
{}

void Rock::update() {
    // Super update
    Object::update();
    
    // Passed the player, reset it back to te right side
    if (position.x < 0) {
        position.x = 105;
        // Random didn't seem to work
        position.y = (position.y > 63 - size.y) ? 0 : position.y + size.y;
        velocity.x += -1; // Speed up
    }
}

void Rock::render() {
    for (int i = 0; i < size.x; ++i) {
        for (int j = 0; j < size.y; ++j) {
            display.write( hwlib::location( position.x + i, position.y + j ), hwlib::black );
        }
    }
}