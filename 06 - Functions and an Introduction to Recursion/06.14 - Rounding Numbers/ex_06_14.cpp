// Exercise 6.14: ex_06_14.cpp

#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

double roundToInteger( double );
double roundToTenths( double );
double roundToHundredths( double );
double roundToThousandths( double );

int main() {

   for ( int i{ 1 }; i <= 3; ++i ) {

      double number;

      cout << "Number: ";
      cin >> number;

      cout << fixed
         << "\nOriginal value:       "
         << setprecision( 5 ) << number
         << "\nNearest integer:      "
         << setprecision( 0 ) << roundToInteger( number )
         << "\nNearest tenth:        "
         << setprecision( 1 ) << roundToTenths( number )
         << "\nNearest hundredths:   "
         << setprecision( 2 ) << roundToHundredths( number )
         << "\nNearest thousandths:  "
         << setprecision( 3 ) << roundToThousandths( number )
         << '\n' << endl;
   }

   return 0;
}

double roundToInteger( double x ) {
   return floor( x + 0.5 );
}

double roundToTenths( double x ) {
   return floor( x * 10 + 0.5 ) / 10;
}

double roundToHundredths( double x ) {
   return floor( x * 100 + 0.5 ) / 100;
}

double roundToThousandths( double x ) {
   return floor( x * 1000 + 0.5 ) / 1000;
}
