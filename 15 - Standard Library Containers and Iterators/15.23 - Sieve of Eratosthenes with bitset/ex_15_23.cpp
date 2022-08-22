// Exercise 15.23: ex_15_23.cpp
// Sieve of Eratosthenes with bitset

#include <iostream>
#include <bitset>

using namespace std;

int main() {

   const size_t SIZE{ 1024 };
   size_t number;

   bitset< SIZE > prime;
   prime.flip();
   prime.reset( 0 );
   prime.reset( 1 );

   for ( number = 2; number * number < SIZE; ++number )
      if ( prime.test( number ) )
         for ( size_t bit{ number * number }; bit < SIZE; bit += number )
            prime.reset( bit );

   cout << "Prime numbers up to 1023:\n\n";

   for ( number = 2; number < SIZE; ++number )
      if ( prime.test( number ) )
         cout << number << ' ';

   cout << "\n\nPositive number: ";
   cin >> number;

   if ( number < 2 ) number = 0;
   else for ( size_t i{ 2 }; i * i <= number; ++i )
      if ( !( number % i ) )
         number = 0;

   cout << "It is " << ( number ? "" : "not " ) << "prime\n";

   return EXIT_SUCCESS;
}
