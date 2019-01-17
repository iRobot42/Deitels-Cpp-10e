// Exercise 7.13: ex_07_13.cpp

#include <array>
#include <iostream>

using namespace std;

int main() {

   const size_t SIZE{ 20 }; // smallest possible for the "worst case"
   array< int, SIZE > a{};

   cout << "Enter 20 numbers [10-100]...\n" << endl;

   for ( size_t i{ 0 }; i < SIZE; ++i ) {

      int number;

      do {
         cout << "Number " << i + 1 << ": ";
         cin >> number;
      } while ( number < 10 || number > 100 );

      bool skip{ false };

      for ( size_t j{ 0 }; j < i; ++j )
         if ( number == a[ j ] ) {
            skip = true;
            break;
         }

      if ( !skip )
         a[ i ] = number;
   }

   cout << "\nUnique values: " << endl;

   for ( const int& element : a )
      if ( element )
         cout << element << ' ';

   cout << endl;
   return 0;
}
