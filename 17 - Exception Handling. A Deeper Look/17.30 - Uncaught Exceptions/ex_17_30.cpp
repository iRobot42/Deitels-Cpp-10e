// Exercise 17.30: ex_17_30.cpp
// Uncaught Exceptions

#include <iostream>
#include <stdexcept>

using namespace std;

void f() {

   try { throw float(); }
   catch ( bool& ) { cerr << "bool handler\n"; }
   catch ( char& ) { cerr << "char handler\n"; }
}

int main() {

   try { f(); }
   catch ( int& )    { cerr << "int handler\n"; }
   catch ( double& ) { cerr << "double handler\n"; }
   catch ( float& )  { cerr << "float handler\n"; }

   return EXIT_SUCCESS;
}
