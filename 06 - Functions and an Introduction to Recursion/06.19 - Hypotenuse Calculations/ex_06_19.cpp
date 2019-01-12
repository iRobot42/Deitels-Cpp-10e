// Exercise 6.19: ex_06_19.cpp

#include <cmath>
#include <iostream>

using namespace std;

double hypotenuse( double, double );

int main() {

   cout << "1: " << hypotenuse( 3.0, 4.0 )
      << "\n2: " << hypotenuse( 5.0, 12.0 )
      << "\n3: " << hypotenuse( 8.0, 15.0 )
      << endl;

   return 0;
}

double hypotenuse( double s1, double s2 ) {
   return sqrt( s1 * s1 + s2 * s2 );
}
