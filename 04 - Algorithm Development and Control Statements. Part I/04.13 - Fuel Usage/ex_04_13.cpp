// Exercise 4.13: ex_04_13.cpp

#include <iomanip>
#include <iostream>

using namespace std;

int main() {

   int kms;
   int liters;
   int kms_total{ 0 };
   int liters_total{ 0 };

   cout << setprecision( 6 ) << fixed;

   cout << "Enter kilometers driven (-1 to quit): ";
   cin >> kms;

   while ( kms != -1 ) {

      cout << "Enter liters used: ";
      cin >> liters;

      kms_total += kms;
      liters_total += liters;

      cout << "Kms per liter this trip: " << 1.0 * kms / liters << endl;
      cout << "Total kms per liter: " << 1.0 * kms_total / liters_total << endl;

      cout << "\nEnter kilometers driven (-1 to quit): ";
      cin >> kms;
   }

   return 0;
}
