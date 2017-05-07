#ifndef LINE_HPP
#define LINE_HPP

#include "window.hpp"
#include "vector.hpp"
#include "drawable.hpp"

class line : public drawable {
private:
   vector end;
public:
   line( window & w, const vector & location, const vector & end ):
      drawable( w, location, end - location ),
      end( end )
   {}
   void setLocation(const vector& newLocation) { location = newLocation; };
   void setEnd(const vector& newEnd) { end = newEnd; };
   
   void draw() override;
};

#endif // LINE_HPP
