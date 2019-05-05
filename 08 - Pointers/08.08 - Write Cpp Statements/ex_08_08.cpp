// Exercise 8.8: ex_08_08.cpp

#include <iostream>

using namespace std;

int main() {

   const int SIZE{ 5 };
   unsigned int values[ SIZE ]{ 2, 4, 6, 8, 10 }; // a
   unsigned int* vPtr{ nullptr }; // b

   for ( unsigned int subscript{}; subscript < SIZE; ++subscript ) // c
      cout << values[ subscript ] << ' ';
   cout << endl;

   vPtr = values; // d
   vPtr = &values[ 0 ];

   for ( unsigned int offset{}; offset < SIZE; ++offset ) // e
      cout << *( vPtr + offset ) << ' ';
   cout << endl;

   for ( unsigned int offset{}; offset < SIZE; ++offset ) // f
      cout << *( values + offset ) << ' ';
   cout << endl;

   for ( unsigned int subscript{}; subscript < SIZE; ++subscript ) // g
      cout << vPtr[ subscript ] << ' ';
   cout << endl;

   // h: values[ 4 ]; *( values + 4 ); vPtr[ 4 ]; *( vPtr + 4 );
   // i: 1002512, 8
   // j: 1002500, 2

   return 0;
}
