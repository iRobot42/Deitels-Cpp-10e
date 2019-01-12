// Exercise 6.26: ex_06_26.cpp

#include <iomanip>
#include <iostream>

using namespace std;

int celsius( int );
int fahrenheit( int );

int main() {

   cout << "Celsius to Fahrenheit:\n\n";

   for ( int c{ 0 }; c <= 100; ++c )
      cout << setw( 6 ) << c << " - " << fahrenheit( c )
         << ( c % 5 ? '\t' : '\n' );

   cout << "\nFahrenheit to Celsius:\n\n";

   for ( int f{ 32 }; f <= 212; ++f )
      cout << setw( 6 ) << f << " - " << celsius( f )
         << ( f % 5 ? '\t' : '\n' );

   cout << endl;
   return 0;
}

int celsius( int fhr ) {
   return static_cast< int >( ( fhr - 32 ) / 1.8 );
}

int fahrenheit( int cls ) {
   return static_cast< int >( cls * 1.8 + 32 );
}
