// Exercise 6.21: ex_06_21.cpp

#include <iostream>

using namespace std;

bool isMultiple3( int );

int main() {

   while ( true ) {

      int n;

      cout << "Integer number (0 to end): ";
      cin >> n;
      if ( !n ) break;

      cout << n << " is " << ( isMultiple3( n ) ? "" : "not " )
         << "a multiple of 3\n\n";
   }

   return 0;
}

bool isMultiple3( int number ) {
   return !( number % 3 );
}
