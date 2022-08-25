// Exercise 16.12: ex_16_12.cpp
// Palindrome Tester

#include <iostream>
using namespace std;

bool palindromeTester( string s ) {
   const string ORIGINAL{ s };
   reverse( s.begin(), s.end() );
   return s == ORIGINAL;
}

int main() {

   const string S{ "able was i ere i saw elba" };
   cout << S << "\nis " << ( palindromeTester( S ) ? "" : "not " )
      << "a palindrome" << endl;

   return EXIT_SUCCESS;
}
