// Exercise 4.33: ex_04_33.cpp

#include <iostream>

using namespace std;

int main() {

   double a, b, c;

   cout << "Three nonzero values: ";
   cin >> a >> b >> c;

   if ( a + b > c )
      if ( b + c > a )
         if ( c + a > b )
            cout << "Triangle!" << endl;

   return 0;
}
