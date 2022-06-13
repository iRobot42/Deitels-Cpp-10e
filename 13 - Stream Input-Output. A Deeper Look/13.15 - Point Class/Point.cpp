// Exercise 13.15: Point.cpp

#include "Point.h"

using namespace std;

istream& operator>>( istream& in, Point& p ) {

   cin >> p.xCoordinate;

   if ( cin.peek() == ',' || cin.peek() == ' ' )
      cin.ignore();
   else
      cin.clear( ios::failbit );

   cin >> p.yCoordinate;

   return in;
}

ostream& operator<<( ostream& out, const Point& P ) {

   if ( cin.good() )
      out << '(' << P.xCoordinate << ", " << P.yCoordinate << ')';
   else
      out << "Incorrect coordinate";

   return out;
}

Point::Point() {
   xCoordinate = yCoordinate = 0;
}