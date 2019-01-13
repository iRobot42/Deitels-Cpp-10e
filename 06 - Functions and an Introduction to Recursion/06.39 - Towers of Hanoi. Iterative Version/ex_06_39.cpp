// Exercise 6.39: ex_06_39.cpp
// Working on more elegant algorithm...

#include <cmath>
#include <iostream>

using namespace std;

void move( int, int, int );

int main() {

   int d;

   do {
      cout << "Number of disks: ";
      cin >> d;
   } while ( d < 1 );

   const int MOVES{ static_cast< int >( pow( 2, d ) - 1 ) };
   int m{ 0 };

   while ( ++m <= MOVES ) {

      if ( m % 2 )
         move( d, m, 1 );
      else {

         int mv{ m };
         int dsk{ 0 };

         while ( !( mv % 2 ) ) {
            dsk++;
            mv /= 2;
         }

         move( d, m, dsk + 1 );
      }

      cout << endl;
   }

   return 0;
}

void move( int disks, int turn, int d ) {

   int b{ disks % 2 ? 3 : 2 };
   int c{ disks % 2 ? 2 : 3 };

   int m{ static_cast< int >( ( ( turn / pow( 2, d - 1 ) ) - 1 ) / 2 ) };

   if ( d % 2 )
      switch ( m % 3 ) {
      case 0: cout << 1 << " -> " << b; break;
      case 1: cout << b << " -> " << c; break;
      case 2: cout << c << " -> " << 1; break;
      }
   else
      switch ( m % 3 ) {
      case 0: cout << 1 << " -> " << c; break;
      case 1: cout << c << " -> " << b; break;
      case 2: cout << b << " -> " << 1; break;
      }
}
