#include "hwlib.hpp"
#include "two_pin_in.hpp"
#include "pin_out_invert.hpp"

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
    auto buttonLeft = hwlib::target::pin_in(hwlib::target::pins::d31);
    auto buttonRight = hwlib::target::pin_in(hwlib::target::pins::d30);
    
    auto buttonBoth = two_pin_in(buttonLeft, buttonRight);
    
    unsigned int mode = 0x00;
    unsigned int num = 0;
    
    bool pressed = false;
    
    // Could not find the overflow problem, Please forgive me
    
    while(!buttonBoth.get()) {
        if (!buttonRight.get() && num < leds.number_of_pins() && !pressed) {
            hwlib::cout << " More ";
            // Set pressed variable to prevent double presses
            pressed = true;
            ++num;
            // Display more LED's
            mode <<= 1;
            mode |= 1; // set lsb to 1
            
            // Wait a bit
            hwlib::wait_ms(100);
        } else if (!buttonLeft.get() && num > 0 && !pressed) {
            hwlib::cout << " LESS ";
            // Same as above
            pressed = true;
            --num;
            // Display less LED's
            mode >>= 1;
            
            // Wait a bit
            hwlib::wait_ms(100);
        }
        
        // Buttons released
        if(pressed && buttonRight.get() && buttonLeft.get()) {
            hwlib::cout << " Released ";
            pressed = false;
        
            // Actualy set the leds
            leds.set(mode);
        }
    }
    
    leds.set(0x00); // Turn of LED's
}

int main( void ){
    // kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;
    
    auto led0 = hwlib::target::pin_out(hwlib::target::pins::d24);
    auto led1 = hwlib::target::pin_out(hwlib::target::pins::d25);
    auto led1Invert = pin_out_invert(led1);

    auto ds   = hwlib::target::pin_out( hwlib::target::pins::d41 );
    auto shcp = hwlib::target::pin_out( hwlib::target::pins::d42 );
    auto stcp = hwlib::target::pin_out( hwlib::target::pins::d40 );
    auto spi  = hwlib::spi_bus_bit_banged_sclk_mosi_miso( 
        stcp, 
        ds, 
        hwlib::pin_in_dummy 
    );
    auto hc595 = hwlib::hc595( spi, shcp );
    
    // Did not have enough hardware for 8 LED's, but the logic should be the same
    auto leds = hwlib::port_out_from_pins(hc595.p0, hc595.p1, led0, led1Invert);
    
    // buttonMagic(leds); // 2.5.1. HC595 / 2.5.2. Decorator

    kitt(leds, 1000, 10); // 2.5.1. Knipperen
}