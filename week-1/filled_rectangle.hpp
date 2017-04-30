#ifndef FILLED_RECTANGLE_HPP
#define FILLED_RECTANGLE_HPP
#include "window.hpp"

/**
 * @class filled_rectangle
 * @author Nick
 * @date 22/04/2017
 * @file filled_rectangle.hpp
 * @brief filled rectangle 
 */
class filled_rectangle {
private:
    const window& w;
    int x, y, width, height;
public:
    /**
     * @brief constructor
     * @param w window to draw on
     * @param x x position
     * @param y y position
     * @param width width of rectangle
     * @param height height of rectangle
     */
    filled_rectangle(window& w, int x, int y, int width, int height);
    /**
     * @brief Render the rectangle 
     */
    void print() const;
    /**
     * @brief Move rectangle on x axis 
     * @param steps number of steps to move
     */
    void moveX(int steps) { x += steps; };
};

#endif // FILLED_RECTANGLE_HPP
