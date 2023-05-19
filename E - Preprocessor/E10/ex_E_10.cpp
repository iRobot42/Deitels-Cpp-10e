// Exercise E.10: ex_E_10.cpp

#include <iostream>
using namespace std;

#define SUMARRAY( a, n ) \
   { int s{}; for ( int i{}; i < n; ++i ) s += a[ i ]; cout << s << endl; }

int main() {

   const int A[]{ 42, -1, 0, 365 }, N{ sizeof( A ) / sizeof( *A ) };
   SUMARRAY( A, N );

   return EXIT_SUCCESS;
}
