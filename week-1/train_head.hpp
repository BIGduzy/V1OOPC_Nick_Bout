#ifndef TRAIN_HEAD_HPP
#define TRAIN_HEAD_HPP

#include "window.hpp"
#include "filled_rectangle.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "line.hpp"

/**
 * @class train_head
 * @author Nick
 * @date 22/04/2017
 * @file train_head.hpp
 * @brief Printable train locomotive
 */
class train_head {
    const window& w;
    int x, y;
    filled_rectangle base, base1, link;
    rectangle nose, chimney, chimney1;
    circle wheel, wheel1;
    line nose1, nose2;
    
public:

    /**
     * @brief constructor
     * @param w window to draw on
     * @param x position
     * @param y position
     * @param size of locomotive
     */
    train_head(window& w, int x, int y, int size);
    
    /**
     * @brief render locomotive 
     */
    void print() const;
    
    /**
     * @brief Move rectangle on x axis 
     * @param steps number of steps to move
     */
    void moveX(int steps);
};

#endif // TRAIN_HEAD_HPP
