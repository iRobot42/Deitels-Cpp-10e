// Exercise 16.13: ex_16_13.cpp
// Enhanced Palindrome Tester

#include <algorithm>
#include <iostream>

using namespace std;

bool palindromeTester( string s ) {
   string original; // lowercase alphabet characters only
   copy_if( s.begin(), s.end(), back_inserter( original ),
            []( char& c ){ return isalpha( c = tolower( c ) ); } );
   s = original;
   reverse( s.begin(), s.end() );
   return s == original;
}

int main() {

   const string S{ "Madam, I'm Adam!" };
   cout << S << "\nis " << ( palindromeTester( S ) ? "" : "not " )
      << "a palindrome" << endl;

   return EXIT_SUCCESS;
}
