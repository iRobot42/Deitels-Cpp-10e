// Exercise 6.13: ex_06_13.cpp

#include <cmath>
#include <iostream>

using namespace std;

int main() {

   for ( int i{ 1 }; i <= 5; ++i ) {

      double x;

      cout << "Number: ";
      cin >> x;

      double y{ floor( x + 0.5 ) };
      
      cout << "Nearest integer for " << x << " is " << y << '\n' << endl;
   }

   return 0;
}
