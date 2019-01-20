// Exercise 7.22, part c: ex_07_22_c.cpp

#include <array>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {

   const size_t SIZE{ 8 };   
   
   const array< int, SIZE > horizontal{ 2, 1, -1, -2, -2, -1, 1, 2 };
   const array< int, SIZE > vertical{ -1, -2, -2, -1, 1, 2, 2, 1 };

   array< array< int, SIZE >, SIZE > board{};
   array< array< int, SIZE >, SIZE > accessibility{
      2, 3, 4, 4, 4, 4, 3, 2,
      3, 4, 6, 6, 6, 6, 4, 3,
      4, 6, 8, 8, 8, 8, 6, 4,
      4, 6, 8, 8, 8, 8, 6, 4,
      4, 6, 8, 8, 8, 8, 6, 4,
      4, 6, 8, 8, 8, 8, 6, 4,
      3, 4, 6, 6, 6, 6, 4, 3,
      2, 3, 4, 4, 4, 4, 3, 2 };

   size_t currentRow{ 0 };
   size_t currentColumn{ 0 };

   int counter{ 0 };

   while ( true ) {

      board[ currentRow ][ currentColumn ] = ++counter;
      accessibility[ currentRow ][ currentColumn ] = 0;

      size_t nextRow;
      size_t nextColumn;

      int min{ 9 };

      for ( size_t moveNumber{ 0 }; moveNumber < SIZE; ++moveNumber ) {
      
         size_t testRow{ currentRow + vertical[ moveNumber ] };
         size_t testColumn{ currentColumn + horizontal[ moveNumber ] };
      
         if ( testRow >= 0 && testRow < SIZE && testColumn >= 0
            && testColumn < SIZE && !board[ testRow ][ testColumn ] ) {
         
            --accessibility[ testRow ][ testColumn ];
         
            if ( accessibility[ testRow ][ testColumn ] < min ) {
               min = accessibility[ testRow ][ testColumn ];
               nextRow = testRow;
               nextColumn = testColumn;
            }
         }
      }

      if ( min == 9 ) // initial value indicates that no moves were found
         break;

      currentRow = nextRow;
      currentColumn = nextColumn;
   }

   for ( const auto& row : board ) {
      for ( const auto& element : row )
         cout << setw( 4 ) << element;
      cout << "\n\n";
   }
   
   cout << "Visited squares: " << counter;

   if ( counter == 64 )
      cout << " - FULL TOUR!";

   cout << endl;
   return 0;
}
