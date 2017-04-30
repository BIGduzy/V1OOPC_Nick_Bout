#include "train.hpp"

train::train(window& w, int x, int y, int size, int speed, int numButts):
    w(w),
    x(x),
    y(y),
    size(size),
    speed(speed),
    head(w, x, y, size)
{
    // Add new butts to the butt array
    for (int i = 0; i < numButts; ++i) {
        std::cout << "Adding butts..." << std::endl;
        butts.push_back(train_butt(w, x + (size + 5) * (i + 1), y, size));
    }
}

void train::print() const {
    for (int i = butts.size() - 1; i >= 0; --i) {
        butts[i].print();
    }
    head.print();
}

void train::update(const int& width, const int& height) {
    x -= speed;
    
    int trainSize = ( (size + 5) * (butts.size() + 1) );  // +1 to include the head
    std::cout << (trainSize * -1) << " : " << x << std::endl;
    // If x is less than the full size of the train
    if (x < trainSize * -1) {        
        // Move train back to right side
        // once full train size to get 
        x = width;
        head.moveX(x + trainSize);
        for (int i = butts.size() - 1; i >= 0; --i) {
            butts[i].moveX(x + trainSize);
        }
        
        // Add train butt
        butts.push_back(train_butt(w, x + trainSize, y, size));
        
        // Increase speed
        // ++speed;  // This does not work :(
    } else {
        // Update posotion
        head.moveX(-speed); // Negative speed because we move left
        for (int i = butts.size() - 1; i >= 0; --i) {
            butts[i].moveX(-speed);
        }
    }
}