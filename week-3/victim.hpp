#ifndef VICTIM_HPP
#define VICTIM_HPP
#include "rectangle.hpp"

class Victim : public rectangle {
public:
    /**
     * @brief 
     * @param w Window to draw on
     * @param start Start position
     * @param end End position
     */
    Victim(window & w, const vector & start, const vector & end);
    
    /**
     * @brief Updates the Victim
     * @details
     * Makes the rectangle smaller when hit
     */
    void update() override;
};

#endif // VICTIM_HPP
