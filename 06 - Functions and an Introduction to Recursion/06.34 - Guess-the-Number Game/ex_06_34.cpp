// Exercise 6.34: ex_06_34.cpp

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main() {

   srand( time( 0 ) );

   char play;

   cout << "I have a number between 1 and 1000."
      << "\nCan you guess my number?"
      << "\nPlease type your first guess.\n";

   do {

      const int NUMBER{ 1 + rand() % 1000 };
      int guess;

      cout << endl;

      while ( true ) {

         cout << "Number: ";
         cin >> guess;

         if ( guess == NUMBER )
            break;

         cout << "Too " << ( guess < NUMBER ? "low" : "high" )
            << ". Try again.\n";
      }

      cout << "\nExcellent! You guessed the number!"
         << "\nWould you like to play again (y or n)? ";
      cin >> play;

   } while ( play == 'y' );

   return 0;
}
