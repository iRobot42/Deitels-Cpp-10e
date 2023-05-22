// Exercise F.6: ex_F_06.cpp

#include <cstdlib>
#include <iostream>
using namespace std;

inline void print( const int a[], const int n ) {
   for ( int i{}; i < n; ++i )
      cout << a[ i ] << ' ';
   cout << endl;
}

int main() {

   int s;
   cout << "Size: ";
   cin >> s;

   int* a{ ( int* )calloc( s, sizeof( int ) ) };
   cout << "Values: ";
   for ( int i{}; i < s; ++i )
      cin >> a[ i ];

   cout << "Initialized array: ";
   print( a, s );

   a = ( int* )realloc( a, s / 2 * sizeof( int ) );

   cout << "Reallocated array: ";
   print( a, s / 2 );

   free( a );

   return EXIT_SUCCESS;
}
