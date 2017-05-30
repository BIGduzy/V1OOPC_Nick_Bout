#pragma once
#include "object.hpp"

class Rock : public Object {
public:
    /**
     * @brief constructor
     * @param display Hwlib's oled
     * @param position position of object
     * @param size size of object
     * @param velocity velocity of object
     */
    Rock(hwlib::glcd_oled& display, Vector2d position, Vector2d size, Vector2d velocity);
    
    /**
     * @brief Override of Object's update method
     * 
     * @details
     * Uses super's update to move and checks if out of bound,
     * Then resets to begin, move position.y a bit and makes it faster.
     */
    void update() override;
    /**
     * @brief override of Object's render method
     * 
     * @details
     * Draws a rectangle at position.
     */
    void render() override;
};

