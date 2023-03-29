// Exercise 22.24: ex_22_24.cpp
// Displaying Characters for Given ASCII Codes

#include <iostream>
using namespace std;

int main() {

   short code;
   do {
      cout << "ASCII Code (0 to 255): ";
      cin >> code;
   } while ( 0 > code || code > 255 );

   cout << "Corresponding character: " << ( char )code << endl;

   //for ( int c{}; c < 256; ++c )
   //   cout << c << '\t' << ( char )c << endl;

   return EXIT_SUCCESS;
}
