// Exercise 9.14: ex_09_14.cpp
// HugeInteger Class

#include <iostream>

#include "HugeInteger.h"

using namespace std;

int main() {

   try {

      HugeInteger a, b;

      cout << "Initial value of a is " << a.output()
         << "\nb.isZero() ? " << boolalpha << b.isZero() << "\n\n";

      a.input();
      b.input();
      a.add( b );
      cout << "Sum is " << a.output() << "\n\n";

      a.input();
      b.input();
      a.subtract( b );
      cout << "Difference is " << a.output() << "\n\n";

      a.input();
      b.input();
      a.multiply( b );
      cout << "Product is " << a.output() << "\n\n";

      a.input();
      b.input();
      a.divide( b );
      cout << "Quotient is " << a.output() << "\n\n";

      a.input();
      b.input();
      a.remainder( b );
      cout << "Remainder is " << a.output() << "\n\n";

      a.input();
      b.input();
      cout << "a == b ? " << a.isEqualTo( b )
         << "\na != b ? " << a.isNotEqualTo( b )
         << "\na >  b ? " << a.isGreaterThan( b )
         << "\na <  b ? " << a.isLessThan( b )
         << "\na >= b ? " << a.isGreaterThanOrEqualTo( b )
         << "\na <= b ? " << a.isLessThanOrEqualTo( b ) << endl;
   }
   catch ( const char* ex ) {
      cerr << "Exception: " << ex << endl;
   }

   return 0;
}
