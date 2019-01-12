// Exercise 6.10: ex_06_10.cpp

#include <cmath>
#include <iostream>

using namespace std;

const double PI{ 3.14159 };

inline double sphereVolume( const double radius ) {
   return 4.0 / 3.0 * PI * pow( radius, 3 );
}

int main() {

   double r;

   cout << "Radius of a sphere: ";
   cin >> r;

   cout << "Volume is " << sphereVolume( r ) << endl;

   return 0;
}
