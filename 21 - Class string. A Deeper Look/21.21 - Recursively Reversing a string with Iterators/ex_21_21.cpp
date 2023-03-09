// Exercise 21.21: ex_21_21.cpp
// Recursively Reversing a string with Iterators

#include <iostream>
#include <string>
using namespace std;

void print( string::const_reverse_iterator b,
            const string::const_reverse_iterator e ) {
   if ( b < e ) {
      cout << *b;
      print( ++b, e );
   }
}

int main() {

   string s;

   cout << "String: ";
   getline( cin, s );

   auto b{ s.crbegin() };
   const auto e{ s.crend() };

   print( b, e );

   return EXIT_SUCCESS;
}
