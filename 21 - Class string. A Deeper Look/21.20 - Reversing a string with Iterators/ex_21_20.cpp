// Exercise 21.20: ex_21_20.cpp
// Reversing a string with Iterators

#include <iostream>
#include <string>
using namespace std;

int main() {

   string s;

   cout << "String: ";
   getline( cin, s );

   auto b{ s.crbegin() };
   const auto e{ s.crend() };

   while ( b < e )
      cout << *( b++ );

   return EXIT_SUCCESS;
}
