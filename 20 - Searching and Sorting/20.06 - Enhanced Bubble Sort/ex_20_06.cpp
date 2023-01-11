// Exercise 20.6: ex_20_06.cpp
// Enhanced Bubble Sort

#include <array>
#include <iostream>
using namespace std;

const size_t SIZE{ 5 };

template< typename T >
inline void print( const array< T, SIZE >& ARRAY ) {
   for ( const auto& NUMBER : ARRAY )
      cout << NUMBER << ' ';
   cout << endl;
}

int main() {

   array< int, SIZE > a{ 42, -1, 1024, 0, 365 };

   cout << "Unsorted: ";
   print( a );

   for ( size_t i{ 1 }; i < SIZE - 1; ++i ) {
      bool swapped{};
      for ( size_t j{}; j < SIZE - i; ++j )
         if ( a[ j ] > a[ j + 1 ] ) {
            swap( a[ j ], a[ j + 1 ] );
            swapped = true;
         }
      if ( !swapped )
         break;
   }

   cout << "  Sorted: ";
   print( a );

   return EXIT_SUCCESS;
}
