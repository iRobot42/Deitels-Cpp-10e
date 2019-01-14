// Exercise 6.61: ex_06_61.cpp

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int operation( int, int, int );
int random( int );
void comment( bool );

int main() {

   srand( static_cast< unsigned int >( time( 0 ) ) );

   char again;

   do {

      int difficulty;
      int arithmetic;
      bool rnd{ false };

      do {
         cout << "Difficulty (1-4): ";
         cin >> difficulty;
      } while ( difficulty < 1 || difficulty > 4 );

      cout << "Types of arithmetic problem:"
         << "\n1 - addition"
         << "\n2 - subtraction"
         << "\n3 - multiplication"
         << "\n4 - division (integer)"
         << "\n5 - random mixture" << endl;

      do {
         cout << "Type: ";
         cin >> arithmetic;
      } while ( arithmetic < 1 || arithmetic > 5 );

      if ( arithmetic == 5 ) {
         arithmetic = 1 + rand() % 4;
         rnd = true;
      }

      int number1{ random( difficulty ) };
      int number2{ random( difficulty ) };
      int performance{ 0 };
      const int TRIES{ 10 };

      for ( int i{ 1 }; i <= TRIES; ++i ) {

         while ( arithmetic == 4 && !number2 )
            number2 = random( difficulty );

         int result{ operation( arithmetic, number1, number2 ) };
         int answer;
         
         cin >> answer;

         bool correct{ answer == result };

         comment( correct );

         if ( correct ) {
            performance++;
            number1 = random( difficulty );
            number2 = random( difficulty );
            if ( rnd )
               arithmetic = 1 + rand() % 4;
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

int operation( int op, int n1, int n2 ) {

   switch ( op ) {
   case 1: cout << n1 << " + " << n2 << " = "; return n1 + n2; break;
   case 2: cout << n1 << " - " << n2 << " = "; return n1 - n2; break;
   case 3: cout << n1 << " * " << n2 << " = "; return n1 * n2; break;
   case 4: cout << n1 << " / " << n2 << " = "; return n1 / n2; break;
   default: return 0;
   }
}

int random( int dl ) {
   return rand() % static_cast< int >( pow( 10, dl ) );
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
