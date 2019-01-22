// Exercise 7.27: ex_07_27.cpp

#include <array>
#include <iostream>

using namespace std;

int main() {

   // a

   const size_t SIZE{ 1000 };
   array< bool, SIZE > prime;

   for( bool& number : prime )
      number = true;

   // b

   for ( size_t n{ 2 }; n < SIZE; ++n )
      for ( size_t i{ 2 }; i < n; ++i ) // better: i <= sqrt( n );
         if ( !( n % i ) )
            prime[ n ] = false;

   // output

   cout << "Prime numbers:\n" << endl;

   for ( size_t number{ 2 }; number < SIZE; ++number )
      if ( prime[ number ] )
         cout << number << ' ';

   cout << endl;
   return 0;
}
