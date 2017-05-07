#include "ball.hpp"
#include <iostream>

ball::ball( window & w, const vector & midpoint, int radius, const vector & speed ):
   circle( w, midpoint, radius ),
   speed( speed )
{}

void ball::update(){
   location += speed;
}

void ball::interact( drawable & other ){
    if( this != &other){
        if( overlaps( other )) {
            vector otherBounce = other.getBounce();
            speed.x *= otherBounce.x;
            speed.y *= otherBounce.y;
            hit = true;
            other.setHit(true);
        }
    }
}