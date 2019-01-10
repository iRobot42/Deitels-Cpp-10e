// Exercise 5.29: ex_05_29.cpp

#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {

   double amount;
   double principal{ 24.0 };
   double rate;

   do {
      cout << "Rate (%, 5-10): ";
      cin >> rate;
   } while ( rate < 5 || rate > 10 );

   cout << "\nYear" << setw( 25 ) << "Amount on deposit\n\n";
   cout << fixed << setprecision( 2 );

   for ( int year{ 1626 }; year <= 2018; ++year ) {
      amount = principal * pow( 1.0 + rate / 100, year - 1625 );
      cout << setw( 4 ) << year << setw( 23 ) << amount << endl;
   }

   return 0;
}
