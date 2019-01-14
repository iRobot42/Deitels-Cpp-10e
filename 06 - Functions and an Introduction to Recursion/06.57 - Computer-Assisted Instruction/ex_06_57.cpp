// Exercise 6.57: ex_06_57.cpp

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

inline void ask( int number1, int number2 ) {
   cout << "\nHow much is " << number1 << " times " << number2 << "? ";
}

int main() {

   srand( static_cast< unsigned int >( time( 0 ) ) );

   cout << "Enter -1 to end." << endl;

   int answer;

   do {

      int n1{ rand() % 10 };
      int n2{ rand() % 10 };

      do {

         ask( n1, n2 );
         cin >> answer;

         if ( answer == -1 ) break;

         cout << ( answer == n1 * n2 ?
            "Very good!" : "No. Please try again." ) << endl;

      } while ( answer != n1 * n2 );

   } while ( answer != -1 );

   return 0;
}
