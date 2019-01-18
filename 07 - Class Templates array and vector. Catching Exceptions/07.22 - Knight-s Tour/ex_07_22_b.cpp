// Exercise 7.22, part b: ex_07_22_b.cpp

#include <array>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {

   const size_t SIZE{ 8 };

   array< array< int, SIZE >, SIZE > board{};
   array< int, SIZE > horizontal{ 2, 1, -1, -2, -2, -1, 1, 2 };
   array< int, SIZE > vertical{ -1, -2, -2, -1, 1, 2, 2, 1 };

   size_t currentRow{ 0 };
   size_t currentColumn{ 0 };

   board[ currentRow ][ currentColumn ] = 1;

   int counter{ 1 };
   size_t moveNumber{ 0 };

   while ( moveNumber < SIZE ) {

      size_t testRow{ currentRow + vertical[ moveNumber ] };
      size_t testColumn{ currentColumn + horizontal[ moveNumber ] };

      if ( testRow < 0 || testRow >= SIZE || testColumn < 0
         || testColumn >= SIZE || board[ testRow ][ testColumn ] )
         moveNumber++;
      else {
         currentRow = testRow;
         currentColumn = testColumn;
         board[ currentRow ][ currentColumn ] = ++counter;
         moveNumber = 0;
      }
   }

   for ( const auto& row : board ) {
      for ( const auto& element : row )
         cout << setw( 4 ) << element;
      cout << "\n\n";
   }

   cout << "Visited squares: " << counter << endl;

   return 0;
}
