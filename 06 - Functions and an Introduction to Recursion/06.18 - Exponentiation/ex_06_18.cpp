// Exercise 6.18: ex_06_18.cpp

#include <iostream>

using namespace std;

long integerPower( int, unsigned );

int main() {

   int b;
   unsigned e;

   cout << "Base and exponent: ";
   cin >> b >> e;

   cout << "Result is " << integerPower( b, e ) << endl;

   return 0;
}

long integerPower( int base, unsigned exponent ) {

   long value{ 1 };

   do value *= base;
   while ( --exponent );

   return value;
}
