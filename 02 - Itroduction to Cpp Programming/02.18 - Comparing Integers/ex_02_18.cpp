// Exercise 2.18: ex_02_18.cpp
// Comparing Integers

#include <iostream>
using namespace std;

int main() {

   int number1, number2;

   cout << "Two numbers: ";
   cin >> number1 >> number2;

   if ( number1 == number2 ) {
      cout << "These numbers are equal.\n";
      return 0;
   }

   if ( number2 > number1 )
      number1 = number2;

   cout << number1 << " is larger." << endl;

   return 0;
}
