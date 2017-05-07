#include "window.hpp"
#include "ship.hpp"
#include "ball.hpp"
#include "wall.hpp"
#include "victim.hpp"

int main(){
    const int WIDTH = 128;
    const int HEIGHT = 64;
    window w( vector( WIDTH, HEIGHT ), 2 );
//    ball b( w, vector( 50, 20 ), 9, vector( 5, 2 ) );

    const int WALL_SIZE = 4;
    // The end vector gets -1 on x and y because we count from 0
    Wall wallTop(w,    vector(0, 0),                  vector(WIDTH - 1, WALL_SIZE - 1),  vector(1, -1), 1);
    Wall wallRight(w,  vector(WIDTH - WALL_SIZE, 0),  vector(WIDTH - 1, HEIGHT - 1),     vector(-1, 1), 2);
    Wall wallBottom(w, vector(0, HEIGHT - WALL_SIZE), vector(WIDTH - 1, HEIGHT - 1),     vector(1, -1), 3);
    Wall wallLeft(w,   vector(0, 0),                  vector(WALL_SIZE - 1, HEIGHT - 1), vector(-1, 1));
    
    Ship ship(w, vector(20, 20), vector(10, 5));
    Victim timmy(w, vector(WIDTH * 0.75, HEIGHT - (20 + WALL_SIZE)), vector(WIDTH * 0.75 + 5, HEIGHT - WALL_SIZE));

    drawable* objects[] = { &wallTop, &wallRight, &wallBottom, &wallLeft, &timmy, &ship };

    while(true) {
        // Clear canvas
        w.clear();
        // Render objects
        for( auto & p : objects ){
            p->draw();
        }

        // Wait a bit beause the window clear function is slow
        wait_ms( 100 );

        // Update objects
        for( auto & p : objects ){
            p->update();
        }

        // Collision
        for( auto & p : objects ){
            for( auto & other : objects ){
                p->interact( *other );
            } 
        }
   }
}

