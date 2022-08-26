// Exercise 17.21: ex_17_21.cpp
// Throwing Exceptions from a catch

#include <iostream>
#include <stdexcept>

using namespace std;

int main() {

   try {
      cout << "Function main() throws an exception...\n";
      throw exception{};
   }
   catch ( const exception& ) {
      cout << "The handler itself throws the same exception...\n";
      throw exception{};
   }

   // [ HERE ] no more handlers provided; calling abort()

   cout << "Сontrol returned to main()\n"; // should not be printed

   return EXIT_SUCCESS;
}
