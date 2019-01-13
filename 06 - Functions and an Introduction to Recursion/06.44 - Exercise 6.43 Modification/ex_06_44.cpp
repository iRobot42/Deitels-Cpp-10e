// Exercise 6.44: ex_06_44.cpp

#include <iostream>

using namespace std;

int mystery( int, int );

int main() {

   cout << "Enter two integers: ";

   int x{ 0 };
   int y{ 0 };

   cin >> x >> y;

   cout << "The result is " << mystery( x, y ) << endl;
}

int mystery( int a, int b ) {

   if ( b < 0 ) {
      b *= -1;
      a *= -1;
   }

   return 1 == b ? a : a + mystery( a, b - 1 );
}
