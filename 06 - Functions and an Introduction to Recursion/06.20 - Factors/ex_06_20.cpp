// Exercise 6.20: ex_06_20.cpp

#include <iostream>

using namespace std;

bool isFactor( int, int );

int main() {

   while ( true ) {
      
      int a, b;

      cout << "Two integer numbers (0 to end): ";
      cin >> a;
      if ( !a ) break;
      cin >> b;

      cout << b << " is " << ( isFactor( a, b ) ? "" : "not " )
         << "a factor of " << a << "\n\n";
   }

   return 0;
}

bool isFactor( int n1, int n2 ) {
   return !( n1 % n2 );
}
