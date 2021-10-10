// Exercise 9.11: Rectangle.cpp
// Rectangle class member-function definitions

#include <stdexcept>

#include "Rectangle.h"

using namespace std;

Rectangle::Rectangle( float l, float w ) {

   setLength( l );
   setWidth( w );
}

void Rectangle::setLength( float l ) {

   if ( l <= 0.0 || l >= 20.0 )
      throw invalid_argument( "length must be (0-20)" );
   else length = l;
}

void Rectangle::setWidth( float w ) {

   if ( w <= 0.0 || w >= 20.0 )
      throw invalid_argument( "width must be (0-20)" );
   else width = w;
}

const float Rectangle::getLength() const { return length; }

const float Rectangle::getWidth() const { return width; }

const float Rectangle::perimeter() const {
   return 2 * getLength() + 2 * getWidth();
}

const float Rectangle::area() const {
   return getLength() * getWidth();
}