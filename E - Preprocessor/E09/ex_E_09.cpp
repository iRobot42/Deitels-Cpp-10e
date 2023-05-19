// Exercise E.9: ex_E_09.cpp

#include <iostream>
using namespace std;

#define PRINTARRAY( a, n ) \
   for ( int i{}; i < n; ++i ) cout << a[ i ] << ' '; cout << endl;

int main() {

   const int A[]{ 42, -1, 1024, 0, 365 };
   PRINTARRAY( A, sizeof( A ) / sizeof( *A ) );

   return EXIT_SUCCESS;
}
