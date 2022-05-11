// Exercise 5.30: ex_05_30.cpp
// DollarAmount Constructor with Two Parameters

#include <iomanip>
#include <iostream>
#include <string>

#include "DollarAmount.h"

using namespace std;

int main() {

   DollarAmount d1{ 123, 45 };
   DollarAmount d2{ 15, 76 };

   cout << "After adding d2 (" << d2.toString() << ") into d1 ("
      << d1.toString() << "), d1 = ";
   d1.add( d2 );
   cout << d1.toString() << "\n";

   cout << "After subtracting d2 (" << d2.toString() << ") from d1 ("
      << d1.toString() << "), d1 = ";
   d1.subtract( d2 );
   cout << d1.toString() << "\n";

   cout << "After subtracting d1 (" << d1.toString() << ") from d2 ("
      << d2.toString() << "), d2 = ";
   d2.subtract( d1 );
   cout << d2.toString() << "\n\n";

   cout << "Enter integer interest rate and divisor. For example:\n"
      << "for     2%, enter:    2 100\n"
      << "for   2.3%, enter:   23 1000\n"
      << "for  2.37%, enter:  237 10000\n"
      << "for 2.375%, enter: 2375 100000\n> ";
   
   int rate;
   int divisor;
   
   cin >> rate >> divisor;

   DollarAmount balance{ 1000, 0 };

   cout << "\nInitial balance: " << balance.toString()
      << "\n\nYear" << setw( 20 ) << "Amount on deposit" << endl;

   for ( unsigned int year{ 1 }; year <= 10; year++ ) {
      balance.addInterest( rate, divisor );
      cout << setw( 4 ) << year << setw( 20 ) << balance.toString() << endl;
   }
}
