// Exercise 21.23: ex_21_23.cpp
// Letter Pyramid

#include <iostream>
#include <string>
using namespace std;

int main() {

   string s{ "abcdefghijklmnopqrstuvwxyz" };
   s += '{';

   const int HEIGHT{ 14 };

   for ( int i{}; i < HEIGHT; ++i ) {
      cout << string( HEIGHT - i, ' ' );
      auto b{ s.cbegin() + i };
      for ( int j{}; j <= i; ++j )
         cout << *( b++ );
      b--;
      for ( int j{}; j < i; ++j )
         cout << *( --b );
      cout << endl;
   }

   return EXIT_SUCCESS;
}
