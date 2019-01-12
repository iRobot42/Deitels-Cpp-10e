// Exercise 6.24: ex_06_24.cpp

#include <iostream>

using namespace std;

void separate( int );

int main() {

   int number;

   do {
      cout << "Number (1 - 32767): ";
      cin >> number;
   } while ( number < 1 || number > 32767 );

   separate( number );

   cout << endl;
   return 0;
}

void separate( int n ) {

   int d{ 1 }; // divisor

   while ( n / d )
      d *= 10;

   while ( d > 1 ) {
      cout << n % d / ( d / 10 ) << "  ";
      d /= 10;
   }
}
