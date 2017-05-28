#ifndef TWO_PIN_IN_HPP
#define TWO_PIN_IN_HPP

#include <hwlib.hpp>

class two_pin_in : public hwlib::pin_in {
private:
    hwlib::pin_in* slave0;
    hwlib::pin_in* slave1;
    
public:
    two_pin_in(hwlib::pin_in& slave0, hwlib::pin_in& slave1):
        slave0(&slave0), slave1(&slave1)
    {};
    
    bool get(hwlib::buffering buf = hwlib::buffering::unbuffered) override {
        return !slave0->get() && !slave1->get();
    };
};

#endif // TWO_PIN_IN_HPP
