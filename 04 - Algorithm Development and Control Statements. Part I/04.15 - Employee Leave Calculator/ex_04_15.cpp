// Exercise 4.15: ex_04_15.cpp

#include <iomanip>
#include <iostream>

using namespace std;

int main() {

   double hours;

   cout << setprecision( 2 ) << fixed;

   cout << "Enter number of hours worked (-1 to end): ";
   cin >> hours;

   while ( hours != -1 ) {

      cout << "Accrued leave: " << 2 + hours * 0.1 << " hours\n"
         << "\nEnter number of hours worked (-1 to end): ";
      cin >> hours;
   }

   return 0;
}
