// Exercise 2.19: ex_02_19.cpp

#include <iostream>

using namespace std;

int main() {

   int number1, number2, number3;

   cout << "Input three different integers: ";
   cin >> number1 >> number2 >> number3;

   int min{ number1 };

   if ( number2 < min ) min = number2;
   if ( number3 < min ) min = number3;

   int max{ number1 };

   if ( number2 > max ) max = number2;
   if ( number3 > max ) max = number3;

   cout << "Sum is " << number1 + number2 + number3
      << "\nAverage is " << ( number1 + number2 + number3 ) / 3
      << "\nProduct is " << number1 * number2 * number3
      << "\nSmallest is " << min
      << "\nLargest is " << max << endl;

   return 0;
}
