#include "victim.hpp"

Victim::Victim(window & w, const vector & start, const vector & end):
    rectangle(w, start, end)
{}

void Victim::update() {
    // NOTE: When the victim is not visible anymore, we should remove it from the drawable array
    if (hit && (end.x - location.x > 0 || end.y - location.y > 0)) {
        location.x++;
        location.y++;
        end.x--;
        end.y--;

        // Remove the remaining pixel
        if (end.x - location.x <= 0) end.x = location.x;
        if (end.y - location.y <= 0) end.y = location.y;

        // Why does rectangle use lines Q.Q
        // vector(start.x, start.y), vector(end.x,   start.y)
        top.setLocation(location);
        top.setEnd(vector(end.x, location.y));
        
        // vector(end.x, start.y ), vector( end.x, end.y)
        right.setLocation(vector(end.x, location.y));
        right.setEnd(end);
        
        // vector(start.x, end.y), vector(end.x, end.y)
        bottom.setLocation(vector(location.x, end.y));
        bottom.setEnd(end);
        
        // vector(start.x, start.y), vector(start.x, end.y)
        left.setLocation(location);
        left.setEnd(vector(location.x, end.y));
    }
}