// Exercise 7.34: ex_07_34.cpp

#include <array>
#include <ctime>
#include <iostream>
#include <random>

using namespace std;

const size_t SIZE{ 12 };

void mazeGenerator( array< array< char, SIZE >, SIZE >&, int&, int& );

int main() {

   array< array< char, ::SIZE >, ::SIZE > maze{};

   for ( auto& row : maze )
      for ( auto& element : row )
         element = '#';

   int startRow{ 1 }; // 1...10
   int startCol{ 0 };

   mazeGenerator( maze, startRow, startCol );

   for ( const auto& row : maze ) {
      for ( const auto& element : row )
         cout << element << ' ';
      cout << endl;
   }

   return 0;
}

void mazeGenerator( array< array< char, ::SIZE >, ::SIZE >& m,
   int& row, int& col ) {

   default_random_engine gen{ static_cast< unsigned >( time( 0 ) ) };
   uniform_int_distribution< size_t > uid( 0, 1 );

   for ( size_t r{ 1 }; r < ::SIZE; r += 2 )
      for ( size_t c{ 1 }; c < ::SIZE; c += 2 ) {

         size_t dir{ uid( gen ) };
         
         if ( dir && r - 1 && c != ::SIZE - 1 )
            m[ r - 1 ][ c ] = '.';
         else if ( c - 1 && r != ::SIZE - 1 )
            m[ r ][ c - 1 ] = '.';
         else if ( r - 1 && c != ::SIZE - 1 )
            m[ r - 1 ][ c ] = '.';

         if ( r != ::SIZE - 1 && c != ::SIZE - 1 )
            m[ r ][ c ] = '.';
      }

   m[ row ][ col ] = '.'; // entrance
   m[ 9 ][ 11 ] = '.'; // exit
}
