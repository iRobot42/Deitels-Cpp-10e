// Exercise E.4: ex_E_04.cpp

#include <iostream>
#include <iomanip>
using namespace std;

#define PI 3.14159
#define SV( r ) 4.0 * PI * ( r ) * ( r ) * ( r ) / 3

int main() {

   cout << "radius\t volume\n" << string( 15, '-' ) << endl;
   cout << fixed << setprecision( 2 );

   for ( int i{ 1 }; i <= 10; ++i )
      cout << setw( 6 ) << i << '\t'
           << setw( 7 ) << SV( i ) << endl;

   return EXIT_SUCCESS;
}
