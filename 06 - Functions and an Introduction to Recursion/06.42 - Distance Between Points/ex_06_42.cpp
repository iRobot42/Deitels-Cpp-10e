// Exercise 6.42: ex_06_42.cpp

#include <cmath>
#include <iostream>

using namespace std;

double distance( double, double, double, double );

int main() {

   double aX, aY, bX, bY;

   cout << "1st point (x y): ";
   cin >> aX >> aY;
   cout << "2nd point (x y): ";
   cin >> bX >> bY;

   cout << "\nDistance is " << distance( aX, aY, bX, bY ) << endl;

   return 0;
}

double distance( double x1, double y1, double x2, double y2 ) {
   return sqrt( pow( x1 - x2, 2 ) + pow( y1 - y2, 2 ) );
}
