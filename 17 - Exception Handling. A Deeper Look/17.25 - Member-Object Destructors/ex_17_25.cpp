// Exercise 17.25: ex_17_25.cpp
// Member-Object Destructors

#include <iostream>
#include <exception>

using namespace std;

struct Member {
   Member( const char C ) : NAME{ C } { if ( C == 'D' ) throw exception{}; };
   ~Member() { cout << '~' << NAME << endl; }
   const char NAME;
};

class Object { const Member A{'A'}, B{'B'}, C{'C'}, D{'D'}, E{'E'}; };

int main() {

   try { Object object; }
   catch ( const exception& ) {}

   return EXIT_SUCCESS;
}
