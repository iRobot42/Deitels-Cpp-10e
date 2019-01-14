// Exercise 6.59: ex_06_59.cpp

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

void comment( bool );

int main() {

   srand( static_cast< unsigned int >( time( 0 ) ) );

   char again;

   do {

      int number1{ rand() % 10 };
      int number2{ rand() % 10 };
      int performance{ 0 };
      const int TRIES{ 10 };

      for ( int i{ 1 }; i <= TRIES; ++i ) {

         cout << "How much is " << number1 << " times " << number2 << "? ";

         int answer;
         cin >> answer;         

         bool correct{ answer == number1 * number2 };

         comment( correct );

         if ( correct ) {
            performance++;
            number1 = rand() % 10;
            number2 = rand() % 10;
         }
      }

      cout << endl << ( performance >= TRIES * 0.75 ?
         "Congratulations, you are ready to go to the next level!"
         : "Please ask your teacher for extra help." )
         << "\nContinue (y/n)? ";
      cin >> again;
      
      cout << endl;

   } while ( again == 'y' );

   return 0;
}

void comment( bool isCorrect ) {

   if ( isCorrect )
      switch ( 1 + rand() % 4 ) {
      case 1: cout << "Very good!"; break;
      case 2: cout << "Excellent!"; break;
      case 3: cout << "Nice work!"; break;
      case 4: cout << "Keep up the good work!"; break;
      }
   else
      switch ( 1 + rand() % 4 ) {
      case 1: cout << "No. Please try again."; break;
      case 2: cout << "Wrong. Try once more."; break;
      case 3: cout << "Don't give up!"; break;
      case 4: cout << "No. Keep trying."; break;
      }

   cout << endl;
}
