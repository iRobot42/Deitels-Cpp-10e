// Exercise 22.8: ex_22_08.cpp
// Division and multiplication via bit shifting

#include <iostream>
using namespace std;

inline unsigned int power2( unsigned int number, unsigned int pow ) {
   return number << pow;
}

inline unsigned int divide2( unsigned int number, unsigned int pow ) {
   return number >> pow;
}

int main() {

   unsigned int x{ 16 }, y{ 3 }; // test

   cout << x << " * (2 ^ " << y << ") = " << power2( x, y ) << endl
        << x << " / (2 ^ " << y << ") = " << divide2( x, y ) << endl;

   return EXIT_SUCCESS;
}
