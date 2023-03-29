// Exercise 22.25: ex_22_25.cpp
// Character Handling Functions

#include <iostream>
using namespace std;

int is_digit( int );
int is_alpha( int );
int is_alnum( int );
int is_xdigit( int );
int is_lower( int );
int is_upper( int );
int to_lower( int );
int to_upper( int );
int is_space( int );
int is_cntrl( int );
int is_punct( int );
int is_print( int );
int is_graph( int );

int main() {

   cout << "is_digit( '0' ) == " << is_digit( '0' )
      << "\nis_digit( 'a' ) == " << is_digit( 'a' )
      << "\nis_digit( '!' ) == " << is_digit( '!' )
      << '\n'
      << "\nis_alpha( '1' ) == " << is_alpha( '1' )
      << "\nis_alpha( 'g' ) == " << is_alpha( 'g' )
      << "\nis_alpha( 'G' ) == " << is_alpha( 'G' )
      << "\nis_alpha( '~' ) == " << is_alpha( '~' )
      << '\n'
      << "\nis_alnum( '9' ) == " << is_alnum( '9' )
      << "\nis_alnum( 'z' ) == " << is_alnum( 'z' )
      << "\nis_alnum( '&' ) == " << is_alnum( '&' )
      << '\n'
      << "\nis_xdigit( '3' ) == " << is_xdigit( '3' )
      << "\nis_xdigit( 'F' ) == " << is_xdigit( 'F' )
      << "\nis_xdigit( 'g' ) == " << is_xdigit( 'g' )
      << "\nis_xdigit( '#' ) == " << is_xdigit( '#' )
      << '\n'
      << "\nis_lower( '4' ) == " << is_lower( '4' )
      << "\nis_lower( 'q' ) == " << is_lower( 'q' )
      << "\nis_lower( 'Q' ) == " << is_lower( 'Q' )
      << "\nis_lower( '-' ) == " << is_lower( '-' )
      << '\n'
      << "\nis_upper( '2' ) == " << is_upper( '2' )
      << "\nis_upper( 'q' ) == " << is_upper( 'q' )
      << "\nis_upper( 'Q' ) == " << is_upper( 'Q' )
      << "\nis_upper( '+' ) == " << is_upper( '+' )
      << '\n'
      << "\nto_lower( '6' ): " << ( char )to_lower( '6' )
      << "\nto_lower( 'm' ): " << ( char )to_lower( 'm' )
      << "\nto_lower( 'N' ): " << ( char )to_lower( 'N' )
      << "\nto_lower( '@' ): " << ( char )to_lower( '@' )
      << '\n'
      << "\nto_upper( '8' ): " << ( char )to_upper( '8' )
      << "\nto_upper( 'M' ): " << ( char )to_upper( 'M' )
      << "\nto_upper( 'n' ): " << ( char )to_upper( 'n' )
      << "\nto_upper( '.' ): " << ( char )to_upper( '.' )
      << '\n'
      << "\nis_space( '_' ) == "   << is_space( '_' )
      << "\nis_space( ' ' ) == "   << is_space( ' ' )
      << "\nis_space( '\\t' ) == " << is_space( '\t' )
      << "\nis_space( '\\a' ) == " << is_space( '\a' )
      << '\n'
      << "\nis_cntrl( ' ' ) == "   << is_cntrl( ' ' )
      << "\nis_cntrl( 'o' ) == "   << is_cntrl( 'o' )
      << "\nis_cntrl( '\\n' ) == " << is_cntrl( '\n' )
      << "\nis_cntrl( '\\a' ) == " << is_cntrl( '\a' )
      << '\n'
      << "\nis_punct( ' ' ) == " << is_punct( ' ' )
      << "\nis_punct( '^' ) == " << is_punct( '^' )
      << "\nis_punct( 'v' ) == " << is_punct( 'v' )
      << "\nis_punct( '<' ) == " << is_punct( '<' )
      << '\n'
      << "\nis_print( ' ' ) == "   << is_print( ' ' )
      << "\nis_print( 'b' ) == "   << is_print( 'b' )
      << "\nis_print( '\\b' ) == " << is_print( '\b' )
      << '\n'
      << "\nis_graph( ' ' ) == "   << is_graph( ' ' )
      << "\nis_graph( 'r' ) == "   << is_graph( 'r' )
      << "\nis_graph( '\\r' ) == " << is_graph( '\r' )
      << endl;

   return EXIT_SUCCESS;
}

int is_digit( int c ) {
   return c >= 48 && c <= 57;
}

int is_alpha( int c ) {
   return c >= 65 && c <= 90 || c >= 97 && c <= 122;
}

int is_alnum( int c ) {
   return is_digit( c ) | is_alpha( c );
}

int is_xdigit( int c ) {
   return is_digit( c ) | ( c >= 65 && c <= 70 || c >= 97 && c <= 102 );
}

int is_lower( int c ) {
   return c >= 97 && c <= 122;
}

int is_upper( int c ) {
   return c >= 65 && c <= 90;
}

int to_lower( int c ) {
   return is_upper( c ) ? c + 32 : c;
}

int to_upper( int c ) {
   return is_lower( c ) ? c - 32 : c;
}

int is_space( int c ) {
   return ( c >= 9 && c <= 13 ) || c == 32;
}

int is_cntrl( int c ) {
   return c >= 7 && c <= 13;
}

int is_punct( int c ) {
   return !is_space( c ) && !is_alnum( c );
}

int is_print( int c ) {
   return c >= 32 && c <= 126;
}

int is_graph( int c ) {
   return c >= 33 && c <= 126;
}
