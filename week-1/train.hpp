#ifndef TRAIN_HPP
#define TRAIN_HPP

#include <iostream>
#include <vector>
#include "train_butt.hpp"
#include "train_head.hpp"
#include "window.hpp"

/**
 * @class train
 * @author Nick
 * @date 22/04/2017
 * @file train.hpp
 * @brief Printable train object using train_head and train_body classes
 * 
 */
class train {
private:
    window& w;
    int x, y, size, speed;
    train_head head;
    std::vector<train_butt> butts;
public:
    /**
     * @brief contructor
     * @param w window object to draw on
     * @param x position
     * @param y position
     * @param size size of train_head and train_butt
     * @param speed train speed
     * @param numButts number of wagons
     */
    train(window& w, int x, int y, int size, int speed, int numButts);
    
    /**
     * @brief renders the train 
     */
    void print() const;
    
    /**
     * @brief updates train
     * 
     *  Moves train based on speed, returns it back to the right side when to far left.
     *  Then creates a new train_butt and adds it to the butt vector
     * 
     * @param width window width
     * @param height window height
     */
    void update(const int& width, const int& height);
};

#endif // TRAIN_HPP
