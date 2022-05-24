// Exercise 13.12: ex_13_12.cpp
// Displaying numbers in different bases

#include <iomanip>
#include <iostream>

using namespace std;

int main() {

   const int WIDTH{ 10 };
   int lower{}, upper{};

   do {
      cout << "Limits: ";
      cin >> lower >> upper;
   } while ( lower < 0 || lower >= upper );

   cout << endl << setw( WIDTH ) << "DEC"
                << setw( WIDTH ) << "OCT"
                << setw( WIDTH ) << "HEX" << endl;
   for ( int i{}; i < WIDTH * 3; ++i ) cout << '-';
   cout << endl << showbase;

   for ( int number{ lower }; number <= upper; ++number )
      cout << setw( WIDTH ) << dec << number
           << setw( WIDTH ) << oct << number
           << setw( WIDTH ) << hex << number << endl;

   return 0;
}
