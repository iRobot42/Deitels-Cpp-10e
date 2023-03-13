// Exercise 22.9: ex_22_09.cpp
// Printing a Binary Representation of an Integer Value

#include <iostream>
using namespace std;

void displayBits( unsigned );

int main() {

   unsigned inputValue;

   cout << "Unsigned integer: ";
   cin >> inputValue;

   displayBits( inputValue );

   return EXIT_SUCCESS;
}

void displayBits( unsigned value ) {

   const unsigned SHIFT{ 8 * sizeof( unsigned ) - 1 };
   unsigned mask{ static_cast< const unsigned >( 1 << SHIFT ) };

   for ( unsigned i{ 1 }; i <= SHIFT + 1; ++i ) {
      cout << ( value & mask ? '1' : '0' ) << ( i % 8 ? "" : " " );
      mask >>= 1;
   }

   cout << endl;
}
