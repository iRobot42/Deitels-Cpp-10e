// Exercise 17.26: ex_17_26.cpp
// Placement of exception handlers

#include <iostream>
#include <stdexcept>

using namespace std;

class CustomRTE : public runtime_error {
public: CustomRTE() : runtime_error{ "42" } {}
};

int main() {

   try { throw CustomRTE{}; }
   catch ( const exception& ) { cerr << "Base handler\n"; }
   catch ( const CustomRTE& ) { cerr << "User handler\n"; }

   return EXIT_SUCCESS;
}
