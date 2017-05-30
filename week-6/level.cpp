#include "Level.hpp"

Level::Level(hwlib::glcd_oled& display, hwlib::target::pin_in& buttonLeft, hwlib::target::pin_in& buttonRight):
    display(display),
    buttonLeft(buttonLeft),
    buttonRight(buttonRight),
    player(display, Vector2d(5, 34), Vector2d(10, 10)),
    rock0(display, Vector2d(105, 34), Vector2d(10, 10), Vector2d(-6, 0))
{}

void Level::init() {    
    // Reset player position
    player.setPosition(5, 34);
    rock0.setPosition(105, 34);
    score = 0;
}

void Level::handleInput() {
    // Check for buttons
    if (!buttonRight.get() && !buttonRightPressed) {
        buttonRightPressed = true;        
        // Wait a bit
        hwlib::wait_ms(100);
    }
    
    if (!buttonLeft.get() && !buttonLeftPressed) {
        buttonLeftPressed = true;
        // Wait a bit
        hwlib::wait_ms(100);
    }
    
    // Check for release of left button
    if(buttonLeftPressed && buttonLeft.get()) {
        buttonLeftPressed = false;
    }
    
    // Check for release of right button
    if(buttonRightPressed && buttonRight.get()) {
        buttonRightPressed = false;
    }
}

void Level::update() {
    // Handle buttons
    handleInput();
    
    // Update player
    player.update(buttonLeftPressed, buttonRightPressed);
    score++;
    
    // Update Rocks
    rock0.update();
    
    
    // Game over
    if (player.overlaps(rock0)) {
        hwlib::cout << "Game over!" << hwlib::endl;
        hwlib::cout << "Score: " << score << hwlib::endl;
        
        if (score < 25) {
            hwlib::cout << "Meh" << hwlib::endl;
        } else if (score < 50) {
            hwlib::cout << "Mediocre" << hwlib::endl;
        } else if (score < 75) {
            hwlib::cout << "Nice" << hwlib::endl;
        } else if (score < 150) {
            hwlib::cout << "Great!" << hwlib::endl;
        } else {
            hwlib::cout << "Woa!!" << hwlib::endl;
        }
        
        init();
    }
}

void Level::render() {    
    // Clear screen
    display.clear();
    
    // Render player
    player.render();
    
    // Render Rocks
    rock0.render();
}