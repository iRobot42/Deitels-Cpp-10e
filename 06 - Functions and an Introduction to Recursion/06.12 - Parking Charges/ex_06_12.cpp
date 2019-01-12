// Exercise 6.12: ex_06_12.cpp

#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

double calculateCharges( double );

int main() {

   double hours;
   double total_charges{ 0.0 };
   double total_hours{ 0.0 };

   cout << fixed << "Parking hours (three cars): ";

   for ( int i{ 1 }; i <= 3; ++i ) {

      cin >> hours;

      double charge{ calculateCharges( hours ) };

      total_hours += hours;
      total_charges += charge;

      cout << ( i == 1 ? "\nCar\tHours\tCharge\n" : "" ) << i
         << setw( 12 ) << setprecision( 1 ) << hours
         << setw( 9 ) << setprecision( 2 ) << charge << endl;
   }

   cout << "TOTAL"
      << setw( 8 ) << setprecision( 1 ) << total_hours
      << setw( 9 ) << setprecision( 2 ) << total_charges << endl;

   return 0;
}

double calculateCharges( double h ) {

   double charge{ 20.0 };

   if ( h > 3 ) {

      charge += ceil( h - 3 ) * 5;

      if ( charge > 50 )
         charge = 50;
   }

   return charge;
}
