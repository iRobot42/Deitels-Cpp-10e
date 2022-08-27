// Exercise 17.27: ex_17_27.cpp
// Order of Exception Handlers

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

   try { throw CustomRTE{}; }
   catch ( const CustomRTE& ) { cerr << "User handler\n"; }
   catch ( const exception& ) { cerr << "Base handler\n"; }

   return EXIT_SUCCESS;
}
