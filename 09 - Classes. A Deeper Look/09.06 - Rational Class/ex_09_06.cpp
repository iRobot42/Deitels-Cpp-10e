// Exercise 9.6: ex_09_06.cpp
// Rational Class

#include <iostream>

#include "Rational.h"

using namespace std;

int main() {

   Rational n1{ 2, -4 };
   Rational n2;

   cout << "Initial: "
      << n1.toRationalString() << ", " << n2.toRationalString() << endl;

   n2.setN( 3 );
   n2.setD( 2 );

   cout << n1.toRationalString() << " + " << n2.toRationalString() << " = ";
   n1.add( n2 );
   cout << n1.toRationalString() << " = " << n1.toDouble() << endl;

   cout << n1.toRationalString() << " - " << n2.toRationalString() << " = ";
   n1.subtract( n2 );
   cout << n1.toRationalString() << " = " << n1.toDouble() << endl;

   cout << n1.toRationalString() << " * " << n2.toRationalString() << " = ";
   n1.multiply( n2 );
   cout << n1.toRationalString() << " = " << n1.toDouble() << endl;

   cout << n1.toRationalString() << " / " << n2.toRationalString() << " = ";
   n1.divide( n2 );
   cout << n1.toRationalString() << " = " << n1.toDouble() << endl;

   return 0;
}
