// Exercise 7.4: ex_07_04.cpp

#include <array>
#include <iostream>
using namespace std;

int main() {

   const size_t arraySize{ 4 };
   array< array< int, arraySize >, arraySize > table; // a

   // b: 16

   for ( size_t row{ 0 }; row < table.size(); ++row ) // c
      for ( size_t col{ 0 }; col < table[ row ].size(); ++col )
         table[ row ][ col ] = row * col;

   table = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };

   // d
   cout << "\t[0]\t[1]\t[2]\t[3]\n" << endl;
   for ( size_t row{ 0 }; row < arraySize; ++row ) {
      cout << '[' << row << "]\t";
      for ( size_t col{ 0 }; col < arraySize; ++col )
         cout << table[ row ][ col ] << '\t';
      cout << endl;
   }

   return 0;
}
