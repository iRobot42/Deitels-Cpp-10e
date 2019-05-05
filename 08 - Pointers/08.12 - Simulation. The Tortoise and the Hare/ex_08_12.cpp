// Exercise 8.12: ex_08_12.cpp

#include <ctime>
#include <iomanip>
#include <iostream>
#include <random>

using namespace std;

void moveTortoise( int* const, const int );
void moveHare( int* const, const int );

int main() {

   default_random_engine gen{ static_cast< unsigned >( time( 0 ) ) };
   uniform_int_distribution< int > uid{ 1, 50 };

   int t{ 1 }; // tortoise's position
   int h{ 1 }; // hare's position

   const int F{ 70 }; // finish

   cout << "BANG !!!!!\nAND THEY'RE OFF !!!!!" << endl;

   do {

      int i{ uid( gen ) };

      moveTortoise( &t, i );
      moveHare( &h, i );

      if ( t < h )
         cout << setw( t ) << 'T' << setw( h - t ) << 'H';
      else if ( h < t )
         cout << setw( h ) << 'H' << setw( t - h ) << 'T';
      else
         cout << setw( t + 6 ) << "OUCH!!!";
      cout << endl;

   } while ( t < F && h < F );

   if      ( t >= F && h < F ) cout << "TORTOISE WINS!!! YAY!!!";
   else if ( h >= F && t < F ) cout << "Hare wins. Yuck.";
   else                        cout << "It's a tie.";
   cout << endl;

   return 0;
}

void moveTortoise( int* const POS_PTR, const int RND ) {

   if      ( RND <= 25 ) *POS_PTR += 3; // fast plod
   else if ( RND <= 33 ) *POS_PTR -= 6; // slip
   else                  *POS_PTR += 1; // slow plod

   if ( *POS_PTR < 1 ) *POS_PTR = 1;
}

void moveHare( int* const POS_PTR, const int RND ) {
   
   if      ( RND <= 19 ) return;         // sleep
   else if ( RND <= 27 ) *POS_PTR += 11; // big hop
   else if ( RND <= 35 ) *POS_PTR -= 9;  // big slip
   else if ( RND <= 45 ) *POS_PTR += 1;  // small hop
   else                  *POS_PTR -= 2;  // small slip

   if ( *POS_PTR < 1 ) *POS_PTR = 1;
}
