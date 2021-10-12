// Exercise 9.13: Rectangle.cpp
// Rectangle class member-function definitions

#include <iostream>
#include <stdexcept>

#include "Rectangle.h"

using namespace std;

Rectangle::Rectangle() {}

Rectangle::Rectangle( const float* aPtr, const float* bPtr, const float* cPtr,
                      const float* dPtr, const char F, const char P ) {
   
   setPoints( aPtr, bPtr, cPtr, dPtr );
   setFillCharacter( F );
   setPerimeterCharacter( P );
}

void Rectangle::setPoints( const float* aPtr, const float* bPtr,
                           const float* cPtr, const float* dPtr ) {

   if (  aPtr[ 0 ] < 0.0 || aPtr[ 0 ] > ML   // Ax
      || aPtr[ 1 ] < 0.0 || aPtr[ 1 ] > ML   // Ay
      || bPtr[ 0 ] < 0.0 || bPtr[ 0 ] > ML   // Bx
      || bPtr[ 1 ] < 0.0 || bPtr[ 1 ] > ML   // By
      || cPtr[ 0 ] < 0.0 || cPtr[ 0 ] > ML   // Cx
      || cPtr[ 1 ] < 0.0 || cPtr[ 1 ] > ML   // Cy
      || dPtr[ 0 ] < 0.0 || dPtr[ 0 ] > ML   // Dx
      || dPtr[ 1 ] < 0.0 || dPtr[ 1 ] > ML ) // Dy
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

void Rectangle::setPerimeterCharacter( const char C ) { pc = C; }

void Rectangle::setFillCharacter( const char C ) { fc = C; }

void Rectangle::scale( const float SF ) { // relative to point A
   
   const float XMAX{ ( d[ 0 ] - a[ 0 ] ) * SF + a[ 0 ] },
               YMAX{ ( d[ 1 ] - a[ 1 ] ) * SF + a[ 1 ] };
   
   if ( SF <= 0 || XMAX > ML || YMAX > ML )
      throw invalid_argument( "wrong scaling factor" );
   else {
      b[ 0 ] = d[ 0 ] = XMAX;
      c[ 1 ] = d[ 1 ] = YMAX;
   }
}

void Rectangle::move( const float DX, const float DY ) {

   if ( a[ 0 ] + DX < 0 || a[ 1 ] + DY < 0
      || d[ 0 ] + DX >= QS || d[ 1 ] + DY >= QS )
      throw invalid_argument( "wrong offset value" );
   else {
      dx = DX;
      dy = DY;
   }
}

float Rectangle::length() const {
   const float S1{ b[ 0 ] - a[ 0 ] };
   const float S2{ c[ 1 ] - a[ 1 ] };
   return S1 > S2 ? S1 : S2;
}

float Rectangle::width() const {
   const float S1{ b[ 0 ] - a[ 0 ] };
   const float S2{ c[ 1 ] - a[ 1 ] };
   return S1 < S2 ? S1 : S2;
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
      << " and area " << area() << '.' << endl;
}

void Rectangle::draw() const {
   
   const float XMIN{ trunc( a[ 0 ] + dx ) }, XMAX{ trunc( d[ 0 ] + dx ) },
               YMIN{ trunc( a[ 1 ] + dy ) }, YMAX{ trunc( d[ 1 ] + dy ) };

   cout << "Visual representation inside a " << QS << "-by-" << QS
      << " box with offset (" << dx << ';' << dy << "):\n";

   for ( float y{ QS - 1 }; y >= 0.0; --y ) {

      for ( float x{ 0.0 }; x < QS; ++x )
         if ( ( y == YMIN || y == YMAX ) && x >= XMIN && x <= XMAX
            || ( x == XMIN || x == XMAX ) && y >= YMIN && y <= YMAX )
            cout << pc << ' '; // perimeter
         else if ( x > XMIN && x < XMAX && y > YMIN && y < YMAX )
            cout << fc << ' '; // fill
         else if ( !x && !y ) cout << "0-"; // origin
         else if ( !x ) cout << "| "; // Y-axis
         else if ( !y ) cout << "--"; // X-axis
         else cout << "  "; // background

      cout << endl;
   }
}