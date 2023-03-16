// Exercise 22.11: ex_22_11.cpp
// Setting bits in an integer

#include <iostream>
using namespace std;

inline void setBit( unsigned& number, unsigned bit ) {
   number |= ( true << bit );
}

int main() {

   unsigned n{ 11 }, b{ 2 };

   cout << "Unsigned number: " << n << endl;
   setBit( n, b );
   cout << "Bit " << b << " was set: " << n << endl;

   return EXIT_SUCCESS;
}
