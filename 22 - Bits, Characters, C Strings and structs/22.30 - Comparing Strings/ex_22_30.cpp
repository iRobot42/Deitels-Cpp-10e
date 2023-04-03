// Exercise 22.30: ex_22_30.cpp
// Comparing Strings

#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main() {

   string s1, s2;

   cout << "String 1: ";
   getline( cin, s1 );
   cout << "String 2: ";
   getline( cin, s2 );

   int cmp{ strcmp( &s1[ 0 ], &s2[ 0 ] ) };

   cout << s1 << ' ' << ( !cmp ? '=' : cmp > 0 ? '>' : '<' ) << ' ' << s2
      << endl;

   return EXIT_SUCCESS;
}
