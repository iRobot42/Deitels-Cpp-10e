// Exercise 6.58: ex_06_58.cpp

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

void comment( bool );

int main() {

   srand( static_cast< unsigned int >( time( 0 ) ) );

   cout << "Enter -1 to end." << endl;

   int answer;

   do {

      int number1{ rand() % 10 };
      int number2{ rand() % 10 };

      do {

         cout << "\nHow much is " << number1 << " times " << number2 << "? ";
         cin >> answer;

         if ( answer == -1 ) break;

         comment( answer == number1 * number2 );

      } while ( answer != number1 * number2 );

   } while ( answer != -1 );

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
