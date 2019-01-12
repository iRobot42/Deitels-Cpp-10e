// Exercise 6.36: ex_06_36.cpp

#include <iostream>

using namespace std;

long power( int, int );

int main() {

   int b, e;

   do {
      cout << "Base and exponent: ";
      cin >> b >> e;
   } while ( e < 1 );

   cout << "Result is " << power( b, e ) << endl;

   return 0;
}

long power( int base, int exponent ) {
   return exponent == 1 ? base : base * power( base, --exponent );
}
