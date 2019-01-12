// Exercise 6.35: ex_06_35.cpp

#include <ctime>
#include <iostream>
#include <random> // using C++11 randomizer

using namespace std;

int main() {

   default_random_engine generator{ static_cast< unsigned >( time( 0 ) ) };
   uniform_int_distribution< int > uid{ 1, 1000 };

   char play;

   cout << "I have a number between 1 and 1000."
      << "\nCan you guess my number?"
      << "\nPlease type your first guess.\n";

   do {

      const int NUMBER{ uid( generator ) };
      int guess;
      int count{ 0 };

      cout << endl;

      while ( true ) {

         cout << "Number: ";
         cin >> guess;

         count++;

         if ( guess == NUMBER )
            break;

         cout << "Too " << ( guess < NUMBER ? "low" : "high" )
            << ". Try again.\n";
      }

      cout << "\nExcellent! You guessed the number!" << endl;

      if ( count < 10 )
         cout << "Either you know the secret or you got lucky!";
      else if ( count == 10 )
         cout << "Ahah! You know the secret!";
      else
         cout << "You should be able to do better!";

      cout << "\nWould you like to play again (y or n)? ";
      cin >> play;

   } while ( play == 'y' );

   return 0;
}
