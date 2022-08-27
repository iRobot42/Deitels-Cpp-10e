// Exercise 17.24: ex_17_24.cpp
// Local-Variable Destructors

#include <iostream>
#include <stdexcept>

using namespace std;

struct Object { ~Object() { cout << "~\n"; } };

int main() {

   try {
      Object a, b, c;
      cout << "Throwing...\n";
      throw exception{};
   }
   catch ( const exception& ) {
      cout << "Handling...\n";
   }

   return EXIT_SUCCESS;
}
