// Exercise 21.9: ex_21_09.cpp
// Converting a string to title case

#include <iostream>
#include <string>
using namespace std;

int main() {

   string s;

   cout << "String: ";
   getline( cin, s );

   s[ 0 ] = toupper( s[ 0 ] );

   for ( size_t i{ 1 }; i < s.size(); ++i )
      if ( s[ i - 1 ] == ' ' || s[ i - 1 ] == '\"' )
         s[ i ] = toupper( s[ i ] );

   cout << "Converted: " << s << endl;

   return EXIT_SUCCESS;
}
