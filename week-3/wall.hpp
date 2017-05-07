#ifndef WALL_HPP
#define WALL_HPP
#include "rectangle.hpp"
#include "vector.hpp"

class Wall : public rectangle {
private:
    vector start;
    bool filled = true;
    int toggle_interval, toggle_time = 0;
public:
    /**
     * @brief constructor
     * @param w Window to draw on
     * @param start Start vector
     * @param end End vector
     * @param bounce Bounce direction when a object interacts with the wall (direction applies on other object)
     * @param toggle_interval Number of updates before the filled variable is inverted, 4 by default
     */
    Wall(window& w, const vector& start, const vector& end, const vector& bounce, const int& toggle_interval = 4);
    
    /**
     * @brief Draws the Wall
     * @details
     * Draws a rectangle at given coordinate vectors (start, end) and fills it when filled is true
     * This function is a override from the rectangle class
     */
    void draw() override;
    
    /**
     * @brief Updates the wall
     * @details
     * Increments the toggle_time and inverts the filled variable when its greater than the interval
     * This function is a override from the rectangle class
     */    
    void update() override;
};

#endif // WALL_HPP
