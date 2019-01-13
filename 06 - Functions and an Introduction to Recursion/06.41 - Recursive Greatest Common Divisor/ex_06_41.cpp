// Exercise 6.41: ex_06_41.cpp

#include <iostream>

using namespace std;

int gcd( int, int );

int main() {

   int n1, n2;

   cout << "Two numbers: ";
   cin >> n1 >> n2;

   cout << "GCD is " << gcd( n1, n2 ) << endl;

   return 0;
}

int gcd( int x, int y ) {

   if ( x < 0 ) x *= -1;
   if ( y < 0 ) y *= -1;

   int temp;

   if ( x < y ) {
      temp = x;
      x = y;
      y = temp;
   }

   return !y ? x : gcd( y, x % y );
}
