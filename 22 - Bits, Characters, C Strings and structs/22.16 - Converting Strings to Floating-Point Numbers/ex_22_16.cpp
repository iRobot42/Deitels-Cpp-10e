// Exercise 22.16: ex_22_16.cpp
// Converting Strings to Floating-Point Numbers

#include <cstdlib>
#include <iostream>
using namespace std;

int main( int argc, char** argv ) { // 3.14159 0 -1.00 2.718

   double total{};

   cout << "Command-line arguments: ";
   for ( int i{ 1 }; i < argc; ++i ) {
      cout << argv[ i ] << ' ';
      total += atof( argv[ i ] );
   }

   cout << "\nTotal: " << total << endl;

   return EXIT_SUCCESS;
}
