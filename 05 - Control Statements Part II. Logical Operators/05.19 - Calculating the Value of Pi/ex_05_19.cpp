// Exercise 5.19: ex_05_19.cpp

#include <iostream>

using namespace std;

int main() {

   double pi{ 0.0 };

   cout << "Step\tPi\n" << endl;

   for ( int i{ 1 }; i <= 200000; ++i ) {

      double term{ 4.0 / ( i * 2 - 1 ) };

      i % 2 ? pi += term : pi -= term;

      cout << i << '\t' << pi << endl; // 3.14159 - step 130658
   }

   return 0;
}
