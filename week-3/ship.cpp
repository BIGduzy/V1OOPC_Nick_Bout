#include "ship.hpp"
#include <iostream>

Ship::Ship(window & w, const vector & location, const vector & size, const int& move_speed, const int& attack_speed):
    drawable(w, location, size),
    move_speed(move_speed),
    attack_speed(attack_speed)
{}

void Ship::draw() {
    // Draw ship
    int endX = location.x + size.x;
    int endY = location.y + size.y;
    for(int i = location.x; i < endX; ++i) {
        for (int j = location.y; j < endY; ++j) {
            w.draw(vector(i, j));
        }
    }
    
    // Draw bullets
    for (auto& cur : bullets) {
        cur.draw();
    }
}

void Ship::update() {
    // Update ship
    // Position
    // pos.y > max and going down or pos.y < min and going up
    if ((location.y > 64 - size.y * 2 && !dir) || (location.y < 0 + size.y * 2 && dir)) {
        dir = !dir;
    }
    
    // true = up; false = down;
    if (dir) location.y -= move_speed;
    else location.y += move_speed;


    // Attack
    if (attack_timer > attack_speed && bullets.size() < MAX_BULLETS) {
        attack_timer = 0;
        bullets.push_back(ball( w, location + vector(size.x, size.y / 2), 2, vector( 5, 0 ) ));
    } else {
        attack_timer++;
    }

    // Update bullets
    for (auto& cur : bullets) {
        cur.update();
    }
}

void Ship::interact( drawable & other ) {
    for (auto& cur : bullets) {
        cur.interact(other);
    }
}