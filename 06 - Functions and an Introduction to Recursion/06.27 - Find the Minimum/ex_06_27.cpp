// Exercise 6.27: ex_06_27.cpp

#include <iostream>

using namespace std;

double smallest( double, double, double );

int main() {

   double d1, d2, d3;

   cout << "Three double numbers: ";
   cin >> d1 >> d2 >> d3;

   cout << "Smallest is " << smallest( d1, d2, d3 ) << endl;

   return 0;
}

double smallest( double min, double n2, double n3 ) {
   if ( n2 < min ) min = n2;
   return n3 < min ? n3 : min;
}
