#include "Object.hpp"

Object::Object(hwlib::glcd_oled& display, Vector2d position, Vector2d size):
    display(display),
    position(position),
    size(size)
{}

Object::Object(hwlib::glcd_oled& display, Vector2d position, Vector2d size, Vector2d velocity):
    display(display),
    position(position),
    size(size),
    velocity(velocity)
{}

bool within(int x, int a, int b) {
   return (x >= a && x <= b);
}

bool Object::overlaps(const Object& other) {
   bool x_overlap = within( 
      position.x, 
      other.position.x, 
      other.position.x + other.size.x
   ) || within( 
      other.position.x, 
      position.x, 
      position.x + size.x
   );
     
   bool y_overlap = within( 
      position.y, 
      other.position.y, 
      other.position.y + other.size.y
   ) || within( 
      other.position.y, 
      position.y, 
      position.y + size.y
   );
   
   return x_overlap && y_overlap;
}


void Object::update() {
    position += velocity;
}