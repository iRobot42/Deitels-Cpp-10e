// Exercise 6.47: ex_06_47.cpp

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

bool run();
int rollDice();
void chatter();

int main() {

   srand( static_cast< unsigned int >( time( 0 ) ) );
   
   char playAgain;
   int bankBalance{ 1000 };
   int wager;

   cout << "Current balance is $" << bankBalance << endl;

   do {

      cout << endl;

      do {
         cout << "Your wager: ";
         cin >> wager;
      } while ( wager <= 0 || wager > bankBalance );

      if ( run() ) {

         cout << "Player wins" << endl;
         bankBalance += wager;
      }
      else {

         cout << "Player loses" << endl;
         bankBalance -= wager;

         if ( !bankBalance ) {
            cout << "Sorry. You busted!" << endl;
            break;
         }
      }

      cout << "Balance is $" << bankBalance << "\nPlay again (y/n)? ";
      cin >> playAgain;

   } while ( playAgain == 'y' );

   return 0;
}

int rollDice() {

   int die1{ 1 + rand() % 6 };
   int die2{ 1 + rand() % 6 };
   int sum{ die1 + die2 };
      
   cout << "Player rolled " << die1 << " + " << die2 << " = " << sum << endl;

   return sum;
}

bool run() {

   enum class Status { CONTINUE, WON, LOST };

   Status gameStatus;
   int myPoint{ rollDice() };

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
      cout << "Point is " << myPoint << endl;
      chatter();
   }

   while ( Status::CONTINUE == gameStatus )
      if ( rollDice() == myPoint )
         gameStatus = Status::WON;
      else if ( rollDice() == 7 )
         gameStatus = Status::LOST;

   return Status::LOST == gameStatus ? false : true;
}

void chatter() {

   switch ( rand() % 3 ) {
   case 0:
      cout << "Oh, you're going for broke, huh?";
      break;
   case 1:
      cout << "Aw cmon, take a chance!";
      break;
   case 2:
      cout << "You're up big. Now's the time to cash in your chips!";
      break;
   }

   cout << endl;
}
