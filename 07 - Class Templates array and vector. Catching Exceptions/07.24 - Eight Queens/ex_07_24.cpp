// Exercise 7.24: ex_07_24.cpp

#include <array>
#include <iostream>

using namespace std;

int main() {

   const size_t SIZE{ 8 };

   array< array< bool, SIZE >, SIZE > board{};
   array< array< bool, SIZE >, SIZE > eliminated{};
   
   // The best starting points are at the edges of the chessboard.
   // According to heuristic, they have smallest elimination number (22).

   int currentRow{ 0 };
   int currentCol{ 2 };

   while ( true ) {

      board[ currentRow ][ currentCol ] = true;

      for ( int row{}; row < SIZE; ++row )
         for ( int col{}; col < SIZE; ++col )
            if ( row == currentRow || col == currentCol )
               eliminated[ row ][ col ] = true;

      for ( int diag{ 1 }; diag < SIZE; ++diag ) {

         const int RP{ currentRow + diag };
         const int RM{ currentRow - diag };
         const int CP{ currentCol + diag };
         const int CM{ currentCol - diag };

         if ( RP < SIZE && CP < SIZE ) eliminated[ RP ][ CP ] = true;
         if ( RP < SIZE && CM >= 0   ) eliminated[ RP ][ CM ] = true;
         if ( RM >= 0   && CM >= 0   ) eliminated[ RM ][ CM ] = true;
         if ( RM >= 0   && CP < SIZE ) eliminated[ RM ][ CP ] = true;
      }

      int min{ 22 }; // smallest elimination number

      for ( int row{}; row < SIZE; ++row )
         for ( int col{}; col < SIZE; ++col )
            if ( !eliminated[ row ][ col ] ) {

               int c{}; // elimination number, counter

               for ( int r{}; r < SIZE; ++r )
                  for ( int c{}; c < SIZE; ++c )
                     if ( r == row || c == col )
                        c++;

               for ( int d{ 1 }; d < SIZE; ++d ) {

                  const int RP{ row + d };
                  const int RM{ row - d };
                  const int CP{ col + d };
                  const int CM{ col - d };

                  if ( RP < SIZE && CP < SIZE && !eliminated[ RP ][ CP ] ) c++;
                  if ( RP < SIZE && CM >= 0   && !eliminated[ RP ][ CM ] ) c++;
                  if ( RM >= 0   && CM >= 0   && !eliminated[ RM ][ CM ] ) c++;
                  if ( RM >= 0   && CP < SIZE && !eliminated[ RM ][ CP ] ) c++;
               }

               if ( c < min ) {
                  min = c;
                  currentRow = row;
                  currentCol = col;
               }
            }

      if ( min == 22 )
         break;
   }

   for ( const auto& row : board ) {
      for ( const auto& element : row )
         cout << ' ' << ( element ? 'Q' : '.' );
      cout << endl;
   }

   return 0;
}
