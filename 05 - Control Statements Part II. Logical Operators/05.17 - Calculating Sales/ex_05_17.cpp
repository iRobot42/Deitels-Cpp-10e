// Exercise 5.17: ex_05_17.cpp

#include <iomanip>
#include <iostream>

using namespace std;

int main() {

   double total{ 0.0 };

   int number{ -1 };

   while ( number ) {

      cout << "Product number (1-5) [0 - exit]: ";
      cin >> number;

      if ( number < 1 || 5 < number )
         continue;

      int quantity;

      do {
         cout << "Quantity sold: ";
         cin >> quantity;
      } while ( quantity < 0 );

      switch ( number ) {
      case 1:
         total += quantity * 2.98; break;
      case 2:
         total += quantity * 4.50; break;
      case 3:
         total += quantity * 9.98; break;
      case 4:
         total += quantity * 4.49; break;
      case 5:
         total += quantity * 6.87; break;
      }

      cout << endl;
   }

   cout << fixed << setprecision( 2 )
      << "\nTotal retail value of all products sold is $" << total << endl;

   return 0;
}
