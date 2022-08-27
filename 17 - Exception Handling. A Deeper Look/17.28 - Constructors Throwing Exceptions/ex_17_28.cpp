// Exercise 17.28: ex_17_28.cpp
// Constructors Throwing Exceptions

#include <iostream>
#include <stdexcept>

using namespace std;

int main() {

   struct Object { Object() { throw exception{ "Constructor failure" }; } };
   try { Object object; } catch ( const exception& EX ) { cerr << EX.what(); }

   return EXIT_SUCCESS;
}
