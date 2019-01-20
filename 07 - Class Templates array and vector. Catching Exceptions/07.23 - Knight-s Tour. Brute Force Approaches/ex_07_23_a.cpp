// Exercise 7.23, part a: ex_07_23_a.cpp

#include <array>
#include <iomanip>
#include <iostream>
#include <random>

using namespace std;

int main() {

   default_random_engine generator{ static_cast< unsigned >( time( 0 ) ) };
   uniform_int_distribution< size_t > uid{ 0, 7 };

   const size_t SIZE{ 8 };

   const array< int, SIZE > horizontal{ 2, 1, -1, -2, -2, -1, 1, 2 };
   const array< int, SIZE > vertical{ -1, -2, -2, -1, 1, 2, 2, 1 };

   array< array< int, SIZE >, SIZE > board{};

   size_t currentRow{ 0 };
   size_t currentColumn{ 0 };

   int counter{ 0 };

   board[ currentRow ][ currentColumn ] = ++counter;

   for ( int i{ 0 }; i < 1000; ++i ) {

      size_t moveNumber{ uid( generator ) };
      size_t testRow{ currentRow + vertical[ moveNumber ] };
      size_t testColumn{ currentColumn + horizontal[ moveNumber ] };

      if ( testRow >= 0 && testRow < SIZE && testColumn >= 0
         && testColumn < SIZE && !board[ testRow ][ testColumn ] ) {
         
         currentRow = testRow;
         currentColumn = testColumn;
         board[ currentRow ][ currentColumn ] = ++counter;
      }
   }

   for ( const auto& row : board ) {
      for ( const auto& element : row ) {         
         cout << setw( 4 );
         if ( !element ) cout << '.'; // nice and clean
         else cout << element;
      }
      cout << "\n\n";
   }

   cout << "Visited squares: " << counter << endl;

   return 0;
}
