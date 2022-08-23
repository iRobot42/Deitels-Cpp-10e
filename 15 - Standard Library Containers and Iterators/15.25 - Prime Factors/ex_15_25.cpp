// Exercise 15.25: ex_15_25.cpp
// Prime Factors

#include <iostream>

using namespace std;

bool isPrime( const int NUMBER ) {
   if ( NUMBER < 2 ) return false;
   else for ( int factor{ 2 }; factor * factor <= NUMBER; ++factor )
      if ( !( NUMBER % factor ) )
         return false;
   return true;
}

int main() {

   int number;
   cout << "Number: ";
   cin >> number;

   if ( isPrime( number ) )
      cout << "It is prime";
   else {
      cout << "It is not prime";
      if ( number >= 2 ) {
         cout << "\nThe unique prime factorization is: ";
         const int MID{ number / 2 };
         for ( int factor{ 2 }; factor <= MID; ++factor )
            if ( !( number % factor ) && isPrime( factor ) ) {
               cout << factor << ' ';
               number /= factor--;
            }
      }
   }
   cout << endl;

   return EXIT_SUCCESS;
}
