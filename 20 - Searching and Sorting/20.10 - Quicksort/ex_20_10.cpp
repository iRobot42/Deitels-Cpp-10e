// Exercise 20.10: ex_20_10.cpp
// Quicksort

#include <iostream>
using namespace std;

int partition( int[], int, int );
void quickSort( int[], const int, const int );

int main() {

   int a[]{ 42, -1, 1024, 0, 365 };
   const int SIZE{ sizeof( a ) / sizeof( *a ) };

   cout << "Unsorted: ";
   for ( const auto& NUMBER : a )
      cout << NUMBER << ' ';
   cout << endl;

   quickSort( a, 0, SIZE - 1 );

   cout << "  Sorted: ";
   for ( const auto& NUMBER : a )
      cout << NUMBER << ' ';
   cout << endl;

   return EXIT_SUCCESS;
}

int partition( int a[], int first, int last ) {

   const int NUMBER{ a[ first ] };
   int count{};

   for ( int i{ first + 1 }; i <= last; ++i )
      if ( a[ i ] <= NUMBER )
         count++;

   const int INDEX{ first + count };
   swap( a[ first ], a[ INDEX ] );

   while ( first < INDEX && last > INDEX ) {

      while ( a[ first ] <= NUMBER )
         first++;
      while ( a[ last ] > NUMBER )
         last--;

      if ( first < INDEX && last > INDEX )
         swap( a[ first++ ], a[ last-- ] );
   }

   return INDEX;
}

void quickSort( int a[], const int FIRST, const int LAST ) {

   if ( FIRST >= LAST )
      return;

   const int INDEX{ partition( a, FIRST, LAST ) };
   quickSort( a, FIRST, INDEX - 1 );
   quickSort( a, INDEX + 1, LAST );
}
