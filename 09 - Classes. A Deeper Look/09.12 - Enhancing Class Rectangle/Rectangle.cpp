// Exercise 9.12: Rectangle.cpp
// Rectangle class member-function definitions

#include <iostream>
#include <stdexcept>

#include "Rectangle.h"

using namespace std;

Rectangle::Rectangle() {}

Rectangle::Rectangle( const float* aPtr, const float* bPtr,
                      const float* cPtr, const float* dPtr ) {
   setPoints( aPtr, bPtr, cPtr, dPtr );
}

void Rectangle::setPoints( const float* aPtr, const float* bPtr,
                           const float* cPtr, const float* dPtr ) {

   if (  aPtr[ 0 ] < 0.0 || aPtr[ 0 ] > 20.0   // Ax
      || aPtr[ 1 ] < 0.0 || aPtr[ 1 ] > 20.0   // Ay
      || bPtr[ 0 ] < 0.0 || bPtr[ 0 ] > 20.0   // Bx
      || bPtr[ 1 ] < 0.0 || bPtr[ 1 ] > 20.0   // By
      || cPtr[ 0 ] < 0.0 || cPtr[ 0 ] > 20.0   // Cx
      || cPtr[ 1 ] < 0.0 || cPtr[ 1 ] > 20.0   // Cy
      || dPtr[ 0 ] < 0.0 || dPtr[ 0 ] > 20.0   // Dx
      || dPtr[ 1 ] < 0.0 || dPtr[ 1 ] > 20.0 ) // Dy
      throw out_of_range( "coordinate must be [0-20]" );

   else if ( aPtr[ 0 ] != cPtr[ 0 ] || aPtr[ 1 ] != bPtr[ 1 ]
          || dPtr[ 0 ] != bPtr[ 0 ] || dPtr[ 1 ] != cPtr[ 1 ] )
      throw invalid_argument( "not a rectangle" );

   else {
      a[ 0 ] = aPtr[ 0 ]; a[ 1 ] = aPtr[ 1 ]; // Ax,Ay
      b[ 0 ] = bPtr[ 0 ]; b[ 1 ] = bPtr[ 1 ]; // Bx,By
      c[ 0 ] = cPtr[ 0 ]; c[ 1 ] = cPtr[ 1 ]; // Cx,Cy
      d[ 0 ] = dPtr[ 0 ]; d[ 1 ] = dPtr[ 1 ]; // Dx,Dy
   }
}

float Rectangle::length() const {
   float side1{ b[ 0 ] - a[ 0 ] };
   float side2{ c[ 1 ] - a[ 1 ] };
   return side1 > side2 ? side1 : side2;
}

float Rectangle::width() const {
   float side1{ b[ 0 ] - a[ 0 ] };
   float side2{ c[ 1 ] - a[ 1 ] };
   return side1 < side2 ? side1 : side2;
}

float Rectangle::perimeter() const {
   return 2 * length() + 2 * width();
}

float Rectangle::area() const {
   return length() * width();
}

bool Rectangle::square() const {
   return length() == width();
}

void Rectangle::print() const {

   cout << "Points: A(" << a[ 0 ] << ';' << a[ 1 ] << "), B(" << b[ 0 ]
      << ';' << b[ 1 ] << "), C(" << c[ 0 ] << ';' << c[ 1 ] << "), D("
      << d[ 0 ] << ';' << d[ 1 ] << ").\n";

   if ( !length() || !width() ) cout << "Object is not a rectangle" << endl;
   else cout << "They form a " << ( square() ? "square " : "" ) << length()
      << " by " << width() << " rectangle with perimeter " << perimeter()
      << " and area " << area() << endl;
}