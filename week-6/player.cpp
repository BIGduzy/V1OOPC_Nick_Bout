#include "Player.hpp"

Player::Player(hwlib::glcd_oled& display, Vector2d position, Vector2d size):
    Object(display, position, size)
{}

void Player::update(bool buttonLeftPressed, bool buttonRightPressed) {
    // Call super's update
    Object::update();
    
    // Check for buttons to move
    if (!buttonLeftPressed && !buttonRightPressed) { // both not pressed
        velocity.y = 0;
    } else if (buttonLeftPressed && !buttonRightPressed) { // Left pressed
        velocity.y = SPEED;
    } else if (!buttonLeftPressed && buttonRightPressed) { // Right pressed
        velocity.y = -SPEED;
    }
    
    if (position.y < 0) position.y = 0;
    else if (position.y > 64 - size.y) position.y = 64 - size.y;
}

void Player::render() {
    for (int i = 0; i < size.x; ++i) {
        for (int j = 0; j < size.y; ++j) {
            display.write( hwlib::location( position.x + i, position.y + j ), hwlib::black );
        }
    }
}