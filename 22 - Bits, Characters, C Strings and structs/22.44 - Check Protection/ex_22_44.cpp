// Exercise 22.44: ex_22_44.cpp
// Check Protection

#include <iomanip>
#include <iostream>
using namespace std;

void print( const char* c ) {

   const char S{ 9 };
   char s{ S };

   while ( *c++ ) s--;
   c -= S - s + 1;

   cout << setw( S ) << c << '\n'
      << string( s, '*' ) << c << '\n'
      << string( S, '-' ) << endl;
}

int main() {

   print( "99,999.99" );
   print( "1,230.60" );
   print( "99.87" );

   return EXIT_SUCCESS;
}
