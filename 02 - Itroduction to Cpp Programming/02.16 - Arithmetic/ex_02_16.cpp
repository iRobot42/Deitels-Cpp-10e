// Exercise 2.16: ex_02_16.cpp
// Arithmetic

#include <iostream>
using namespace std;

int main() {

   int number1, number2;

   cout << "Two numbers: ";
   cin >> number1 >> number2;

   cout << "\nSum is " << number1 + number2
      << "\nProduct is " << number1 * number2
      << "\nDifference is " << number1 - number2 << endl;

   if ( number2 != 0 )
      cout << "Quotient is " << number1 / number2 << endl;

   return 0;
}
