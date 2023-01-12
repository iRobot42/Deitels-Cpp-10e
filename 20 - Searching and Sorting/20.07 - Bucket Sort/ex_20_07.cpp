// Exercise 20.7: ex_20_07.cpp
// Bucket Sort

#include <cmath>
#include <iostream>
using namespace std;

int main() {

   int a[]{ 42, 1, 1024, 120, 365 };
   const int SIZE{ sizeof( a ) / sizeof( *a ) };

   cout << "Unsorted: ";
   for ( const auto& NUMBER : a )
      cout << NUMBER << ' ';
   cout << endl;

   int max{ *a };
   for ( const auto& NUMBER : a )
      if ( NUMBER > max )
         max = NUMBER;

   int digits{ 1 };
   while ( max /= 10 )
      digits++;

   for ( int pass{}; pass < digits; ++pass ) {

      int b[ 10 ][ SIZE ]{};
      int position[ 10 ]{};
      int index{};

      // distribution
      for ( const auto& NUMBER : a ) {
         int bucket{ NUMBER / static_cast< int >( pow( 10, pass ) ) % 10 };
         b[ bucket ][ position[ bucket ]++ ] = NUMBER;
      }

      // gathering
      for ( const auto& BUCKET : b )
         for ( const auto& NUMBER : BUCKET )
            if ( NUMBER )
               a[ index++ ] = NUMBER;
            else break;
   }

   cout << "Sorted:   ";
   for ( const auto& NUMBER : a )
      cout << NUMBER << ' ';

   return EXIT_SUCCESS;
}
