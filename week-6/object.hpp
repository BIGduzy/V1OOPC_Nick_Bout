#pragma once
#include <hwlib.hpp>
#include "Vector2d.hpp"

class Object {
protected:
    hwlib::glcd_oled& display;
    Vector2d position, size, velocity = {0, 0};
    
public:

    /**
     * @brief constructor
     * @param display Hwlib's oled
     * @param position position of object
     * @param size size of object
     */
    Object(hwlib::glcd_oled& display, Vector2d position, Vector2d size);
    /**
     * @brief constructor
     * @param display Hwlib's oled
     * @param position position of object
     * @param size size of object
     * @param velocity velocity of object
     */
    Object(hwlib::glcd_oled& display, Vector2d position, Vector2d size, Vector2d velocity);
    
    /**
     * @brief setter for position
     * @param x
     * @param y
     */
    void setPosition(int x, int y) { position.x = x; position.y = y; };
    /**
     * @brief Detects overlapping between 2 objects
     * @param other the other object
     * 
     * @details
     * Checks if one object is within the other for both x and y  
     */
    bool overlaps(const Object& other);
    
    /**
     * @brief Updates the object
     * 
     * @details Adds velocity to position
     */
    virtual void update();
    
    /**
     * @brief Renders the objects
     * 
     * @details abstract method, intended to be overridden
     */
    virtual void render() = 0;
};

