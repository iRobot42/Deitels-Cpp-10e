// Exercise 6.31: ex_06_31.cpp

#include <iostream>

using namespace std;

int gcd( int, int );

int main() {

   int int1, int2;

   do {
      cout << "Two nonzero numbers: ";
      cin >> int1 >> int2;
   } while ( !int1 || !int2 );

   cout << "GCD is " << gcd( int1, int2 ) << endl;

   return 0;
}

int gcd( int x, int y ) {

   if ( x < 0 ) x *= -1;
   if ( y < 0 ) y *= -1;

   while ( x != y ) // Euclidean algorithm
      x > y ? x -= y : y -= x;

   return x;
}
