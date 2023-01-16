// Exercise 21.8: ex_21_08.cpp
// Converting a string to upper case

#include <iostream>
#include <string>
using namespace std;

int main() {

   string s;

   cout << "String: ";
   getline( cin, s );

   string::iterator i{ s.begin() };

   while ( i != s.end() ) {
      *i = toupper( *i );
      i++;
   }

   cout << "Converted: " << s << endl;

   return EXIT_SUCCESS;
}
