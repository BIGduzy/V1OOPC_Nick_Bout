/**
 * @file 
 * @mainpage Author Information
 *  Nick Bout (<a href="https://github.com/BIGduzy">BIGduzy</a>) \n
 *  22/04/2017 \n
 *  Hogeschool Utrecht - Jaar 1 - Blok 4 - OOP
 * @section program_name Program name
 *  Week 1
 */

#include <iostream>
#include "window.hpp"
#include "train.hpp"

int main(int argc, char **argv) {
    const int WINDOW_WIDTH = 128;
    const int WINDOW_HEIGHT = 64;
    
    window w( WINDOW_WIDTH, WINDOW_HEIGHT, 2 );

    // Create train
    train t(w, 50, 20, 30, 2, 1);
    
    while (true) {
        w.clear();  // Clear canvas (slow)
        t.update(WINDOW_WIDTH, WINDOW_HEIGHT); // Update train position
        t.print(); // Render Train
    }
    t.print();

    return 0;
}
