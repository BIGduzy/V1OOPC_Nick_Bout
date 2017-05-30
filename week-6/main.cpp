#include <hwlib.hpp>
#include "level.hpp"

namespace target = hwlib::target;

#define PIN_BUTTON_LEFT hwlib::target::pins::d31
#define PIN_BUTTON_RIGHT hwlib::target::pins::d30

int main( void ){
    
    // kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;
    
    // i2c and OLED
    auto scl = target::pin_oc( target::pins::scl );
    auto sda = target::pin_oc( target::pins::sda );
    auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl,sda );
    auto display = hwlib::glcd_oled( i2c_bus, 0x3c );
    
    // Buttons
    auto buttonLeft = target::pin_in(PIN_BUTTON_LEFT);
    auto buttonRight = target::pin_in(PIN_BUTTON_RIGHT);
    
    Level level = Level(display, buttonLeft, buttonRight);
    level.init(); // Initialize level
    
    // Main loop
    while(true) {
        level.update();
        level.render();
        
        hwlib::wait_ms(10); // Small wait is good
    }
}
