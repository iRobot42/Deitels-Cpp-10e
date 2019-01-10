// Exercise 5.22: ex_05_22.cpp

#include <iostream>

using namespace std;

int main() {

   int x{ 1 };
   int y{ 2 };
   int a{ 3 };
   int b{ 4 };

   //x = y = a = b = 0; // all-to-0 test

   if ( !( x <= 6 && y % 2 == 1 ) == ( !( x <= 6 ) || !( y % 2 == 1 ) ) )
      cout << true;

   if ( !( a < 4 || b >= 6 ) == ( !( a < 4 ) && !( b >= 6 ) ) )
      cout << true;

   if ( ( !( x < 3 ) && !( y >= 2 ) ) == !( x < 3 || y >= 2 ) )
      cout << true;

   if ( ( !( a == b ) || !( b != 2 ) ) == !( a == b && b != 2 ) )
      cout << true;

   cout << endl;
   return 0;
}
