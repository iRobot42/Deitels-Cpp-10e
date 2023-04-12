// Exercise 22.40: ex_22_40.cpp
// String Length Function

#include <iostream>
using namespace std;

size_t str_len( const char* );

int main() {

   char str1[]{ "Not empty string" }, str2[]{ '\0' };

   cout << "str1: " << str1
      << "\nstr2: " << ( *str2 ? str2 : "[empty]" ) << endl
      << "\nstr_len( str1 ) == " << str_len( str1 )
      << "\nstr_len( str2 ) == " << str_len( str2 )
      << "\nstr_len( \"42\" ) == " << str_len( "42" ) << endl;

   return EXIT_SUCCESS;
}

/*size_t str_len( const char* s ) {
   size_t l{};
   while ( s[ l++ ] );
   return --l;
}*/

size_t str_len( const char* s ) {
   size_t l{};
   while ( *s++ ) l++;
   return l;
}
