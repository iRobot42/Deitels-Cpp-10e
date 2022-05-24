// Exercise 13.6: ex_13_06.cpp
// Write C++ Statements

#include <iomanip>
#include <iostream>

using namespace std;

int main() {

   const int SIZE{ 80 };
   char state[ SIZE ], charArray[ SIZE ];

   /* a */ cout << left << setw( 15 ) << 40'000 << endl;
   /* b */ cin.get( state, SIZE );
   /* c */ cout << showpos << 200 << ' ' << noshowpos << 200 << endl;
   /* d */ cout << hex << showbase << 100 << endl;
   /* e */ cin.getline( charArray, 10, 'p' );
   /* f */ cout << setfill( '0' ) << setw( 9 ) << internal << 1.234 << endl;

   return 0;
}
