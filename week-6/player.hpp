#pragma once
#include <hwlib.hpp>
#include "Object.hpp"

class Player : public Object {
private:
    const unsigned int SPEED = 4;
public:
    /**
     * @brief constructor
     * @param display Hwlib's oled
     * @param position position of object
     * @param size size of object
     */
    Player(hwlib::glcd_oled& display, Vector2d position, Vector2d size);
    
    /**
     * @brief Updates player
     * @param buttonLeftPressed if left button is pressed
     * @param buttonRightPressed if right button is pressed
     * 
     * @details This function uses its super's update function,
     * but because we need te parameters we cannot override it.
     * The function prevents the player from going out of bounds and 
     * moves it when buttons are pressed
     */
    void update(bool buttonLeftPressed, bool buttonRightPressed);
    
    
    /**
     * @brief override of Object's render method
     * 
     * @details
     * Draws a rectangle at position.
     */
    void render() override;
};

