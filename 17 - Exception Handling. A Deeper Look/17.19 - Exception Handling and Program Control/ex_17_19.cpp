// Exercise 17.19: ex_17_19.cpp
// Exception Handling and Program Control

#include <iostream>

#include "Quadratic.h"
#include "NoRealRootException.h"

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

   try {
      qe2.solve();
   }
   catch ( const NoRealRootException& EX ) {
      cerr << "Exception: " << EX.what() << endl;
   }

   return EXIT_SUCCESS;
}
