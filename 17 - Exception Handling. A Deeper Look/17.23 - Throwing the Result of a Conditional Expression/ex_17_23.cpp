// Exercise 17.23: ex_17_23.cpp
// Throwing the Result of a Conditional Expression

#include <iostream>
#include <stdexcept>

int main() {

   try { throw true ? int() : double(); }
   catch ( const int& ) { std::cerr << "int\n"; }
   catch ( const double& ) { std::cerr << "double\n"; }

   return EXIT_SUCCESS;
}
