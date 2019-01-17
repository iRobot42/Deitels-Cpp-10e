// Exercise 7.18: ex_07_18.cpp

#include <array>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>

using namespace std;

inline int rollDice( void ) { return 2 + rand() % 6 + rand() % 6; }

int main() {

   enum class Status{ LOST, WON, CONTINUE };

   srand( static_cast< unsigned int >( time( 0 ) ) );

   const int GAMES{ 1000 };
   const int ROLLS{ 21 };

   array< int, ROLLS > wins{};
   array< int, ROLLS > losses{};

   int rollsSum{ 0 };
   int wonSum{ 0 };

   for ( int game{ 0 }; game < GAMES; ++game ) {

      int myPoint{ rollDice() };
      int roll{ 1 };
      Status gameStatus;

      switch ( myPoint ) {
      case 7:
      case 11:
         gameStatus = Status::WON;
         break;
      case 2:
      case 3:
      case 12:
         gameStatus = Status::LOST;
         break;
      default:
         gameStatus = Status::CONTINUE;
      }

      while ( gameStatus == Status::CONTINUE ) {

         int sumOfDice{ rollDice() };
         ++roll;

         if ( sumOfDice == myPoint )
            gameStatus = Status::WON;
         else if ( sumOfDice == 7 )
            gameStatus = Status::LOST;
      }

      rollsSum += roll;

      if ( roll > 20 )
         roll = 0;

      gameStatus == Status::WON ? ++wins[ roll ], ++wonSum : ++losses[ roll ];
   }

   cout << "Roll\tWon\tLost\n--------------------" << endl;

   for ( int i{ 1 }; i < ROLLS; ++i )
      cout << i << '\t' << wins[ i ] << '\t' << losses[ i ] << endl;
   cout << "20+\t" << wins[ 0 ] << '\t' << losses[ 0 ] << endl;

   cout << fixed << setprecision( 2 )
      << "\nChances of winning are " << 100.0 * wonSum / GAMES << " %"
      << "\nAverage game length is " << 1.0 * rollsSum / GAMES << " rolls"
      << endl;

   return 0;
}
