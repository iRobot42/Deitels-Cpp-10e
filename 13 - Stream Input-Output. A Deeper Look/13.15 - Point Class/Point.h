// Exercise 13.15: Point.h

#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point {

   friend std::istream& operator>>( std::istream&, Point& );
   friend std::ostream& operator<<( std::ostream&, const Point& );

public:

   explicit Point();

private:

   int xCoordinate;
   int yCoordinate;
};

#endif