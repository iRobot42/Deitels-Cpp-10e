// Exercise 7.23, part b: ex_07_23_b.cpp

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

   const size_t TOURS{ 1000 };
   array< int, TOURS > tours{};

   for ( int tour{ 0 }; tour < TOURS; ++tour ) {

      array< array< int, SIZE >, SIZE > board{};

      size_t currentRow{ uid( generator ) }; // random initial row
      size_t currentColumn{ uid( generator ) }; // ...and column

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

      tours[ tour ] = counter;
   }

   int best{ 0 };

   for ( size_t i{ 0 }; i < TOURS; ++i ) {
      
      cout << setw( 3 ) << tours[ i ];
      if ( ( i + 1 ) % 25 == 0 ) cout << endl;
      
      if ( tours[ i ] > best )
         best = tours[ i ];
   }

   cout << "\nBest result is " << best << endl;

   return 0;
}
