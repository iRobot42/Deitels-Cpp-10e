// Exercise 22.27: ex_22_27.cpp
// String Searching Functions

#include <cstring>
#include <iostream>
using namespace std;

char*  str_chr  ( const char*, int );
char*  str_rchr ( const char*, int );
size_t str_spn  ( const char*, const char* );
char*  str_pbrk ( const char*, const char* );
size_t str_cspn ( const char*, const char* );
char*  str_str  ( const char*, const char* );

int main() {

   cout << "str_chr( \"iRobot\", \'o\' ) == " << str_chr( "iRobot", 'o' )
      << "\nstr_chr( \"3.1416\", \'1\' ) == " << str_chr( "3.1416", '1' )
      << "\nstr_chr( \"101010\", \'2\' ): " << ( str_chr( "101010", '2' )
                                                 ? "" : "nullptr" ) << '\n'
      << "\nstr_rchr( \"iRobot\", \'o\' ) == " << str_rchr( "iRobot", 'o' )
      << "\nstr_rchr( \"3.1416\", \'1\' ) == " << str_rchr( "3.1416", '1' )
      << "\nstr_rchr( \"101010\", \'2\' ): " << ( str_rchr( "101010", '2' )
                                                  ? "" : "nullptr" ) << '\n'
      << "\nstr_spn( \"iRobot\", \"Rbi\" ) == " << str_spn( "iRobot", "Rbi" )
      << "\nstr_spn( \"3.1416\", \".13\" ) == " << str_spn( "3.1416", ".13" )
      << "\nstr_spn( \"101010\", \"bin\" ): " << ( str_spn( "101010", "bin" )
                                                   ? "" : "nullptr" ) << '\n'
      << "\nstr_pbrk( \"iRobot\", \"t0b\" ) == " << str_pbrk( "iRobot", "t0b" )
      << "\nstr_pbrk( \"3.1416\", \"012\" ) == " << str_pbrk( "3.1416", "012" )
      << "\nstr_pbrk( \"101010\", \"ABC\" ): " << ( str_pbrk( "101010", "ABC" )
                                                    ? "" : "nullptr" ) << '\n'
      << "\nstr_cspn( \"iRobot\", \"4t2\" ) == " << str_cspn( "iRobot", "4t2" )
      << "\nstr_cspn( \"3.1416\", \"601\" ) == " << str_cspn( "3.1416", "601" )
      << "\nstr_cspn( \"101010\", \"0.1\" ) == " << str_cspn( "101010", "0.1" )
      << '\n'
      << "\nstr_str( \"iRobot\", \"Rob\" ) == " << str_str( "iRobot", "Rob" )
      << "\nstr_str( \"3.1416\", \".14\" ) == " << str_str( "3.1416", ".14" )
      << "\nstr_str( \"101010\", \"FFF\" ): " << ( str_str( "101010", "FFF" )
                                                   ? "" : "nullptr" ) << endl;

   return EXIT_SUCCESS;
}

char* str_chr( const char* s, int c ) {
   do if ( *s == c ) return ( char* )s;
   while ( *s++ );
   return nullptr;
}

char* str_rchr( const char* s, int c ) {
   const char* sr{ s + strlen( s ) - 1 };
   do if ( *sr == c ) return ( char* )sr;
   while ( *sr-- );
   return nullptr;
}

size_t str_spn( const char* s1, const char* s2 ) {
   size_t length{};
   do {
      const char* p2{ s2 };
      while ( *p2 && *p2 != *s1 ) p2++;
      if ( !*p2 ) break;
      length++;
   } while ( *s1++ );
   return length;
}

char* str_pbrk( const char* s1, const char* s2 ) {
   do {
      if ( !*s1 ) break;
      const char* p2{ s2 };
      do if ( *p2 == *s1 ) return ( char* )s1;
      while ( *p2++ );
   } while ( *s1++ );
   return nullptr;
}

size_t str_cspn( const char* s1, const char* s2 ) {
   size_t length{};
   do {
      const char* p2{ s2 };
      while ( *p2 && *p2 != *s1 ) p2++;
      if ( *p2 == *s1 ) break;
      length++;
   } while ( *s1++ );
   return length;
}

char* str_str( const char* s1, const char* s2 ) {
   const size_t SIZE{ strlen( s2 ) };
   do if ( !memcmp( s1, s2, SIZE ) ) return ( char* )s1;
   while ( *s1++ );
   return nullptr;
}
