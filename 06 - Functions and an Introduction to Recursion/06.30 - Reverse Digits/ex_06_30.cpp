// Exercise 6.30: ex_06_30.cpp

#include <iostream>

using namespace std;

unsigned reverse( unsigned );

int main() {

   unsigned n;

   cout << "Number: ";
   cin >> n;

   cout << "Reversed is " << reverse( n ) << endl;

   return 0;
}

unsigned reverse( unsigned number ) {

   unsigned div{ 1 };
   
   while ( number / div )
      div *= 10;

   unsigned reversed{ 0 };

   while ( number ) {
      div /= 10;
      reversed += number % 10 * div;
      number /= 10;
   }

   return reversed;
}
