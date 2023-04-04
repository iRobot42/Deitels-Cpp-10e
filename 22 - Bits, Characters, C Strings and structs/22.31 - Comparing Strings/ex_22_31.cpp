// Exercise 22.31: ex_22_31.cpp
// Comparing Strings

#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main() {

   string s1, s2;
   size_t n;

   cout << "String 1: ";
   getline( cin, s1 );
   cout << "String 2: ";
   getline( cin, s2 );
   cout << "Number: ";
   cin >> n;

   int ncmp{ strncmp( &s1[ 0 ], &s2[ 0 ], n ) };

   cout << s1 << ' ' << ( !ncmp ? '=' : ncmp > 0 ? '>' : '<' ) << ' ' << s2
      << endl;

   return EXIT_SUCCESS;
}
