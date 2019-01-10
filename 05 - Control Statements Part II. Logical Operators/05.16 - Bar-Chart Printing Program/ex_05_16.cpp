// Exercise 5.16: ex_05_16.cpp

#include <iostream>

using namespace std;

int main() {

   cout << "Five numbers between 1 and 9: ";

   for ( int n{ 1 }; n <= 5; ++n ) {

      int number;
      cin >> number;

      if ( number < 1 || 9 < number ) {
         cout << "\nNumber " << number << " is out of range!\n";
         continue;
      }

      cout << endl;

      for ( int line{ 1 }; line <= 2; ++line ) {
         for ( int pos{ 1 }; pos <= number; ++pos )
            cout << number;
         cout << endl;
      }
   }

   return 0;
}
