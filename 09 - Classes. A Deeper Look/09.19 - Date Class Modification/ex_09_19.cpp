// Exercise 9.19: ex_09_19.cpp
// Date Class Modification

#include <iostream>

#include "Date.h"

using namespace std;

int main() {

   try {

      Date D0; // local date
      cout << D0.outputMon() << '\n'
           << D0.outputMDY() << '\n'
           << D0.outputDDD() << "\n\n";

      Date D1{ 12, 31, 2000 }; // leap year
      cout << D1.outputMon() << '\n'
           << D1.outputDDD() << "\n\n";

      Date D2{ "March", 2, 2001 }; // common year
      cout << D2.outputMDY() << '\n'
           << D2.outputDDD() << "\n\n";

      Date D3{ 333, 2020 }; // leap year
      cout << D3.outputMon() << '\n'
           << D3.outputMDY() << "\n\n";

      Date D4{ "Octember", 32, 99'999 }; // test
   }
   catch ( const char* ex ) {
      cerr << "Exception: " << ex << endl;
   }

   return 0;
}
