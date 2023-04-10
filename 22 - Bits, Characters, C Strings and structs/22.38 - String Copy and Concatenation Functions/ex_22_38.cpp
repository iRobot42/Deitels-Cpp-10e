// Exercise 22.38: ex_22_38.cpp
// String Copy and Concatenation Functions

#include <iostream>
using namespace std;

char* str_cpy  ( char*, const char* );
char* str_ncpy ( char*, const char*, size_t );
char* str_cat  ( char*, const char* );
char* str_ncat ( char*, const char*, size_t );

int main() {

   const int SIZE{ 80 };
   char str1[ SIZE ]{ "Test" }, str2[ SIZE ]{ "String" };

   cout << "Initial:\n\n  str1: " << str1
                  << "\n  str2: " << str2 << endl;
   cout << "\nstr_cpy( str1, str2 ) == "
           << str_cpy( str1, str2 );
   cout << "\nstr_ncpy( str1 + 5, str2, 3 ) == "
           << str_ncpy( str1 + 5, str2, 3 );
   cout << "\nstr_cat( str1, str2 ) == "
           << str_cat( str1, str2 );
   cout << "\nstr_ncat( str1, str2, 2 ) == "
           << str_ncat( str1, str2, 2 ) << endl;

   return EXIT_SUCCESS;
}

/*char* str_cpy( char* s1, const char* s2 ) {
   for ( int i{}; s1[ i ] = s2[ i++ ]; );
   return s1;
}*/

char* str_cpy( char* s1, const char* s2 ) {
   char* p{ s1 };
   while ( *s1++ = *s2++ );
   return p;
}

/*char* str_ncpy( char* s1, const char* s2, size_t n ) {
   for ( size_t i{}; i < n; ++i ) s1[ i ] = s2[ i ];
   return s1;
}*/

char* str_ncpy( char* s1, const char* s2, size_t n ) {
   char* p{ s1 };
   while ( n-- ) *s1++ = *s2++;
   return p;
}

/*char* str_cat( char* s1, const char* s2 ) {
   int i{}, j{};
   while ( s1[ i ] != '\0' ) i++;
   while ( s1[ i++ ] = s2[ j++ ] );
   return s1;
}*/

char* str_cat( char* s1, const char* s2 ) {
   char* p{ s1 };
   while ( *s1 != '\0' ) s1++;
   while ( *s1++ = *s2++ );
   return p;
}

/*char* str_ncat( char* s1, const char* s2, size_t n ) {
   size_t i{}, j{};
   while ( s1[ i ] != '\0' ) i++;
   while ( j < n ) s1[ i++ ] = s2[ j++ ];
   return s1;
}*/

char* str_ncat( char* s1, const char* s2, size_t n ) {
   char* p{ s1 };
   while ( *s1 != '\0' ) s1++;
   while ( n-- ) *s1++ = *s2++;
   return p;
}
