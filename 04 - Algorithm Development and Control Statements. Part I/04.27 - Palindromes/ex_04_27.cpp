// Exercise 4.27: ex_04_27.cpp

#include <iostream>

using namespace std;

int main() {

   int number{ 0 };

   while ( !number ) {

      cout << "Five-digit number: ";
      cin >> number;

      if ( number < 10000 )
         number = 0;
      if ( number > 99999 )
         number = 0;
   }

   if ( number / 10000 == number % 10 )
      if ( number % 10000 / 1000 == number % 100 / 10 )
         cout << "Palindrome!\n";

   return 0;
}
