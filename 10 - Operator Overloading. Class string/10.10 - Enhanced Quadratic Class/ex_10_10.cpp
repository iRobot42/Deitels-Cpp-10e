// Exercise 10.10: ex_10_10.cpp
// Enhanced Quadratic Class

#include <iostream>

#include "Quadratic.h"

using namespace std;

int main() {

   Quadratic qe1;
   Quadratic qe2{ -1, 3, -4 };

   cout << "Initial:\t" << qe1 << '\t' << qe2 << endl;

   qe1 = qe1 + qe2;
   qe2 = qe2 - qe1;

   cout << "Modified:\t" << qe1 << '\t' << qe2 << endl;

   cout << "Solutions:\t";
   qe1.solve();
   cout << '\t';
   qe2.solve();
   cout << endl;

   return 0;
}
