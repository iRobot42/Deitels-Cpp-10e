// Exercise 6.28: ex_06_28.cpp

#include <cmath>
#include <iostream>

using namespace std;

bool isDudeney( unsigned );

int main() {
   
   cout << "Dudeney numbers:\n" << endl;

   for ( unsigned i{ 1 }; i <= 20'000; ++i ) // according to definition
      if ( isDudeney( i ) )                  // 0 is not positive integer
         cout << i << endl;                  // so I found only six numbers

   return 0;
}

bool isDudeney( unsigned number ) {
      
   int div{ 1 };

   while ( number / div )
      div *= 10;

   int sum{ 0 };

   while ( div > 1 ) {
      sum += number % div / ( div / 10 );
      div /= 10;
   };

   return cbrt( number ) == sum;
}
