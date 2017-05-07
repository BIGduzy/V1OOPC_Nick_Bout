#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <ostream>
#include "window.hpp"
#include "vector.hpp"

class drawable {
protected:
   window w;
   vector location;
   vector size;
   vector bounce = vector(1, 1);
   bool hit = false;
public:
   drawable( window & w, const vector & location, const vector & size );
   
   virtual vector getBounce() const { return bounce; };
   virtual void setHit(const bool& newHit) { hit = newHit; }
   
   bool overlaps( const drawable & other );
   virtual void draw() = 0;
   virtual void update(){}
   virtual void interact( drawable & other ) {}
   
   std::ostream & print( std::ostream & out ) const;
};

std::ostream & operator<<( std::ostream & lhs, const drawable & rhs );

#endif // DRAWABLE_HPP
