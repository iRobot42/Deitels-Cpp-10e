// Exercise 6.29: ex_06_29.cpp

#include <cmath>
#include <iostream>

using namespace std;

bool isPrime( unsigned );

int main() {

   cout << "Prime numbers:\n" << endl;

   for ( unsigned n{ 2 }; n <= 10'000; ++n )
      if ( isPrime( n ) )
         cout << n << ' ';

   cout << endl;
   return 0;
}

bool isPrime( unsigned number ) {

   for ( unsigned i{ 2 }; i <= sqrt( number ); ++i )
      if ( !( number % i ) )
         return false;

   return true;
}
