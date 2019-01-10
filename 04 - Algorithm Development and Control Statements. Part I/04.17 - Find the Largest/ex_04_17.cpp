// Exercise 4.17: ex_04_17.cpp

#include <iostream>

using namespace std;

int main() {

   int counter{ 0 };
   int largest{ 0 };

   while ( ++counter <= 10 ) {

      int number;

      cout << "Number " << counter << ": ";
      cin >> number;

      if ( number > largest )
         largest = number;
   }

   cout << "\nLargest number is " << largest << endl;

   return 0;
}
