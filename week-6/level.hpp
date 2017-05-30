#pragma once
#include <hwlib.hpp>

#include "Player.hpp"
#include "Rock.hpp"

class Level {
private:
    hwlib::glcd_oled& display;
    hwlib::target::pin_in& buttonLeft;
    hwlib::target::pin_in& buttonRight;
    
    bool buttonLeftPressed = false;
    bool buttonRightPressed = false;
    
    unsigned int score = 0;
    
    Player player;
    
    // Getting "If_you_see_this_you_are_using_new_or_malloc" error when i try to put it in a array ;(
    Rock rock0;
public:
    /**
     * @brief Constructor
     * @param display Hwlib's oled used to render objects
     * @param buttonLeft Hwlib pin_in used as left button
     * @param buttonRight Hwlib pin_in used as right button
     */
    Level(hwlib::glcd_oled& display, hwlib::target::pin_in& buttonLeft, hwlib::target::pin_in& buttonRight);
    
    /**
     * @brief Reset the game, used when game over
     */
    void init();
    
    /**
     * @brief handles putton presses 
     */
    void handleInput();
    
    /**
     * @brief Updates level
     * 
     * @details
     * Updates all objects, checks if player overlaps objects,
     * if it does resets the level with the init function.
     */
    void update();
    
    /**
     * @brief Clears the screen and then renders all objects 
     */
    void render();
};

