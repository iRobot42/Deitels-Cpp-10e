// Exercise 22.10: ex_22_10.cpp
// Determining a computer's byte ordering

#include <iostream>
using namespace std;

int main() {

   int number{ 256 }; // 00000000 00000000 00000001 00000000
   char* byte{ ( char* )&number };

   for ( int i{}; i < sizeof( int ); ++i )
      cout << "Byte " << i << ": " << ( int )byte[ i ] << endl;

   return EXIT_SUCCESS;
}
