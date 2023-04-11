// Exercise 22.39: ex_22_39.cpp
// String Comparison Functions

#include <iostream>
using namespace std;

int str_cmp  ( const char*, const char* );
int str_ncmp ( const char*, const char*, size_t );

int main() {

   char str1[]{ "John Doe" }, str2[]{ "John Smith" };

   cout << "str1: " << str1 << "\nstr2: " << str2 << endl

      << "\nstr_cmp( str1, str2 ) == " << str_cmp( str1, str2 )
      << "\nstr_cmp( str2, str1 ) == " << str_cmp( str2, str1 )
      << "\nstr_cmp( str1, \"John Doe\" ) == " << str_cmp( str1, "John Doe" )
      << "\nstr_cmp( \"John\", str2 ) == " << str_cmp( "John", str2 ) << endl

      << "\nstr_ncmp( str1, str2, 5 ) == " << str_ncmp( str1, str2, 5 )
      << "\nstr_ncmp( str1, str2, 6 ) == " << str_ncmp( str1, str2, 6 )
      << "\nstr_ncmp( str2, str1, 6 ) == " << str_ncmp( str2, str1, 6 )
      << "\nstr_ncmp( str1, \"John Deere\", 6 ) == "
      << str_ncmp( str1, "John Deere", 6 ) << endl;

   return EXIT_SUCCESS;
}

/*int str_cmp( const char* s1, const char* s2 ) {
   for ( int i{}; s1[ i ] || s2[ i ]; ++i )
      if ( s1[ i ] != s2[ i ] )
         return s1[ i ] < s2[ i ] ? -1 : 1;
   return 0;
}*/

int str_cmp( const char* s1, const char* s2 ) {
   while ( *s1 || *s2 )
      if ( *s1++ != *s2++ )
         return *--s1 < *--s2 ? -1 : 1;
   return 0;
}

/*int str_ncmp( const char* s1, const char* s2, size_t n ) {
   for ( size_t i{}; i < n && ( s1[ i ] || s2[ i ] ); ++i )
      if ( s1[ i ] != s2[ i ] )
         return s1[ i ] < s2[ i ] ? -1 : 1;
   return 0;
}*/

int str_ncmp( const char* s1, const char* s2, size_t n ) {
   while ( n-- && ( *s1 || *s2 ) )
      if ( *s1++ != *s2++ )
         return *--s1 < *--s2 ? -1 : 1;
   return 0;
}
