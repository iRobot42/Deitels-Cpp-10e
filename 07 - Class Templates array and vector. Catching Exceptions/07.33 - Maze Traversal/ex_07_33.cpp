// Exercise 7.33: ex_07_33.cpp

#include <array>
#include <iostream>

using namespace std;

const size_t SIZE{ 12 };

void mazeTraverse( array< array< char, SIZE >, SIZE >&, int, int );

int main() {

   array< array< char, ::SIZE >, ::SIZE > maze{
      '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
      '#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#',
      '.', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#',
      '#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#',
      '#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', '.',
      '#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#',
      '#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#',
      '#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#',
      '#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#',
      '#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#',
      '#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#',
      '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' };

   mazeTraverse( maze, 2, 0 );

   cout << "Maze solution:\n" << endl;

   for ( const auto& row : maze ) {
      for ( const auto& element : row )
         cout << element << ' ';
      cout << endl;
   }
   
   return 0;
}

void mazeTraverse( array< array< char, ::SIZE >, ::SIZE >& m, int r, int c ) {

   static int d{}; // direction

   m[ r ][ c ] = 'X';
   
   int R{ r }; // next row
   int C{ c }; // next column

   for ( int i{}; i < 4; ++i, d += 3 ) {

      switch ( d %= 4 ) {

      case 0: // east
         if ( r + 1 < ::SIZE && m[ r + 1 ][ c ] != '#' ) {
            d++;
            R = r + 1;
         }
         break;

      case 1: // south
         if ( c - 1 >= 0 && m[ r ][ c - 1 ] != '#' ) {
            d++;
            C = c - 1;
         }
         break;

      case 2: // west
         if ( r - 1 >= 0 && m[ r - 1 ][ c ] != '#' ) {
            d++;
            R = r - 1;
         }
         break;

      case 3: // north
         if ( c + 1 < ::SIZE && m[ r ][ c + 1 ] != '#' ) {
            d++;
            C = c + 1;
         }
         break;
      }

      if ( R != r || C != c )
         break;
   }

   if ( m[ R ][ C ] == 'X' )
      m[ r ][ c ] = 'x';
   
   if ( R == 0 || R == ::SIZE - 1 || C == 0 || C == ::SIZE - 1 ) {
      m[ R ][ C ] = 'X';
      return;
   }
   
   mazeTraverse( m, R, C );
}
