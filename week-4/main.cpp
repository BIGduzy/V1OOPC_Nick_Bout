#include "hwlib.hpp"


/**
 * @brief Executes 1 set of the kitt patern
 * @param leds Container with the leds
 * @param ms Delay in miliseconds between LED shifts
 * 
 * @details
 * This function blinks once LED'S in the following pattern:
 *     XX--
 *     -XX-
 *     --XX
 *     -XX-
 *     XX--
 * Where x equals a turned on LED
 */
 void kittSet(hwlib::port_out& leds, const int& ms) {
    // Loop through the LED's from left to right, exclude the last one because we turn on 2 at the time
    for(unsigned int i = 0; i < leds.number_of_pins() - 1; ++i) {
        // 0x03 == 0011 in binary
        // 1000 turns on the most left led
        // 0001 turns on the most right
        // So we use 0011 and shift it to turn on the 2 leds we want
        leds.set(0x03 << i);
        hwlib::wait_ms(ms);
    }
    
    // Loop through the LED's from right to left, exlude last three because we dont need --XX and turn on 2 LED's from i
    for(unsigned int i = leds.number_of_pins() - 3; i > 0; --i) {
        // Same as above
        leds.set(0x03 << i);
        hwlib::wait_ms(ms);
    }
}

/**
 * @brief Blinks LED's
 * @param leds Container with the 4 leds
 * @param ms Delay in miliseconds between LED shifts
 * @param intervals Number of times the functions needs to be repeated (-1 for infinite)
 * 
 * @details
 * This function uses the kittSet function to repeat the kitt patern multiple times
 * The fuction should work with more than 4 LED's but is not tested due the lack of hardware
 */
void kitt(hwlib::port_out& leds, const int& ms, int intervals = -1) {
    // if intervals = -1 loop infinite
    // Else loop the number of intervals
    if (intervals == -1) {
        while(true) {        
            kittSet(leds, ms);
        }
    } else if (intervals > 0) {
        for (unsigned int i = 0; i < (unsigned)intervals; ++i) {
            kittSet(leds, ms);
        }
    }
    
    leds.set(0x00); // Turn of LED's
}


/**
 * @brief Makes LED's controlable with buttons
 * @param leds Container with the leds
 * 
 * @details
 * Press both buttons to break the while loop
 * Press the left button to turn off most right LED
 * Press the right button to turn on the most right LED
 */
void buttonMagic(hwlib::port_out& leds) {
    auto buttonLeft = hwlib::target::pin_in_out(hwlib::target::pins::d28);
    buttonLeft.direction_set_input();
    auto buttonRight = hwlib::target::pin_in_out(hwlib::target::pins::d29);
    buttonRight.direction_set_input();
    
    unsigned int mode = 0x00;
    unsigned int num = 0;
    
    while(true) {
        if (!buttonLeft.get() && !buttonRight.get()) {
            break;
        } else if (!buttonLeft.get() && num < leds.number_of_pins()) {
            ++num;
            // Display more LED's
            mode <<= 1;
            mode |= 1; // set lsb to 1
        } else if (!buttonRight.get() && num > 0) {
            --num;
            // Display less LED's
            mode >>= 1;
        }
        
        leds.set(mode);
    }

}

int main( void ){
    // kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;
    
    auto led0 = hwlib::target::pin_out(hwlib::target::pins::d22);
    auto led1 = hwlib::target::pin_out(hwlib::target::pins::d23);
    auto led2 = hwlib::target::pin_out(hwlib::target::pins::d24);
    auto led3 = hwlib::target::pin_out(hwlib::target::pins::d25);

    // Put the leds in a container
    auto leds = hwlib::port_out_from_pins( led0, led1, led2, led3 );
    
    // We can't go to fast, else we won't see if its working
    kitt(leds, 1000, 10); // 2.4.3.Patroon
    
    
    buttonMagic(leds); // 2.4.4.Input
}