// Exercise 9.5: ex_09_05.cpp
// Quadratic Equation Class

#include <iostream>

#include "Quadratic.h"

using namespace std;

int main() {

   Quadratic qe1;
   Quadratic qe2{ -1, 3, -4 };

   cout << "Initial:\t" << qe1.toString() << '\t' << qe2.toString() << endl;

   qe1.add( qe2 );
   qe2.subtract( qe1 );

   cout << "Modified:\t" << qe1.toString() << '\t' << qe2.toString() << endl;

   cout << "Solutions:\t";
   qe1.solve();
   cout << '\t';
   qe2.solve();
   cout << endl;

   return 0;
}
