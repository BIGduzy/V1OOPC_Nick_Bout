#ifndef TRAIN_BUTT_HPP
#define TRAIN_BUTT_HPP

#include "circle.hpp"
#include "filled_rectangle.hpp"

/**
 * @class train_butt
 * @author Nick
 * @date 22/04/2017
 * @file train_butt.hpp
 * @brief printable train wagon
 */
class train_butt {
private:
    const window& w;
    int x, y;
    filled_rectangle body, roof, link;
    circle wheel, wheel1;
public:

    /**
     * @brief contructor
     * @param w window to draw on
     * @param x position
     * @param y position
     * @param size of wagon
     */
    train_butt(window& w, int x, int y, int size);
    
    /**
     * @brief render the wagon
     */
    void print() const;
    
    /**
     * @brief Move rectangle on x axis 
     * @param steps number of steps to move
     */
    void moveX(int steps);

};

#endif // TRAIN_BUTT_HPP
