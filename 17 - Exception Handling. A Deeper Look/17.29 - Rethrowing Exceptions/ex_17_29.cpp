// Exercise 17.29: ex_17_29.cpp
// Rethrowing Exceptions

#include <iostream>
#include <stdexcept>

using namespace std;

int main() {

   try {
      try { throw exception{ "42" }; }
      catch (...) { throw; }
   }
   catch ( const exception& EX ) { cerr << EX.what(); }

   return EXIT_SUCCESS;
}
