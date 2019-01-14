// Exercise 6.54: ex_06_54.cpp

#include <ctime>
#include <iostream>
#include <random>

using namespace std;

default_random_engine generator{ static_cast< unsigned >( time( 0 ) ) };

unsigned int rollDice();

int main() {

   enum class Status { CONTINUE, WON, LOST };

   unsigned int myPoint{ 0 };
   Status gameStatus;
   unsigned int sumOfDice{ rollDice() };

   switch ( sumOfDice ) {
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
      myPoint = sumOfDice;
      cout << "Point is " << myPoint << endl;
   }

   while ( Status::CONTINUE == gameStatus ) {

      sumOfDice = rollDice();

      if ( sumOfDice == myPoint )
         gameStatus = Status::WON;
      else if ( sumOfDice == 7 )
         gameStatus = Status::LOST;
   }

   cout << "Player " << ( Status::WON == gameStatus ? "wins" : "loses" )
      << endl;
}

unsigned int rollDice() {
   
   uniform_int_distribution< int > uid{ 1, 6 };

   int die1{ uid( ::generator ) };
   int die2{ uid( ::generator ) };
   int sum{ die1 + die2 };

   cout << "Player rolled " << die1 << " + " << die2 << " = " << sum << endl;

   return sum;
}
