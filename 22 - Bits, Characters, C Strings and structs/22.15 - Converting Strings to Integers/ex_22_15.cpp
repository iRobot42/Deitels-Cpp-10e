// Exercise 22.15: ex_22_15.cpp
// Converting Strings to Integers

#include <cstdlib>
#include <iostream>
using namespace std;

int main( int argc, char** argv ) { // 42 0 -1 365

   int total{};

   cout << "Command-line arguments: ";
   for ( int i{ 1 }; i < argc; ++i ) {
      cout << argv[ i ] << ' ';
      total += atoi( argv[ i ] );
   }

   cout << "\nTotal: " << total << endl;

   return EXIT_SUCCESS;
}
