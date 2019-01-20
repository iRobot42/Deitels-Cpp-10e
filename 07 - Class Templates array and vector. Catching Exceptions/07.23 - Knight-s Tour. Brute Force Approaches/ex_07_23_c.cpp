// Exercise 7.23, part c: ex_07_23_c.cpp

#include <array>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

int main() {

   default_random_engine generator{ static_cast< unsigned >( time( 0 ) ) };
   uniform_int_distribution< size_t > uid{ 0, 7 };

   const size_t SIZE{ 8 };

   const array< int, SIZE > horizontal{ 2, 1, -1, -2, -2, -1, 1, 2 };
   const array< int, SIZE > vertical{ -1, -2, -2, -1, 1, 2, 2, 1 };

   vector< int > tours;

   while ( true ) {

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

      tours.push_back( counter );

      if ( counter == 64 )
         break;
   }

   for ( size_t i{ 0 }; i < tours.size(); ++i ) {
      cout << setw( 3 ) << tours[ i ];
      if ( ( i + 1 ) % 25 == 0 ) cout << endl;
   }

   cout << "\n\nNumber of attempts: " << tours.size() << endl;

   return 0;
}
