// Exercise 6.11: ex_06_11.cpp

#include <cmath>
#include <iostream>

using namespace std;

int main() {

   double x;

   x = fabs( -2.0 ); // a
   cout << "fabs( -2.0 ) = " << x;

   x = fabs( 2.0 ); // b
   cout << "\nfabs( 2.0 ) = " << x;

   x = log( 7.389056 ); // c
   cout << "\nlog( 7.389056 ) = " << x;

   x = sqrt( 16.0 ); // d
   cout << "\nsqrt( 16.0 ) = " << x;

   x = log10( 1000.0 ); // e
   cout << "\nlog10( 1000.0 ) = " << x;

   x = sqrt( 36.0 ); // f
   cout << "\nsqrt( 36.0 ) = " << x;

   x = pow( 2, 3 ); // g
   cout << "\npow( 2, 3 ) = " << x << endl;

   return 0;
}
