// Exercise 22.46: ex_22_46.cpp
// Morse Code

#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <iostream>
using namespace std;

void morse( const char* );

int main() {

   morse( "Morse Code" );
   morse( "-- --- .-. ... .   -.-. --- -.. ." );
   morse( "42" );
   morse( "....- ..---" );
   morse( "... --- ..." );

   return EXIT_SUCCESS;
}

void morse( const char* p ) {

   cout << p << " => ";

   const int SIZE{ 36 };
   const char codes[ SIZE ][ 6 ]{ ".-", "-...", "-.-.", "-..", ".", "..-.",
      "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
      "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",
      "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...",
      "---..", "----." };

   if ( isalnum( *p ) ) { // encoding

      for ( p; *p; ++p )
         cout << ( isalpha( *p ) ? codes[ tolower( *p ) - 97 ] :
                   isdigit( *p ) ? codes[ *p - 22 ] :
                   isspace( *p ) ? " " : "" ) << ' ';
   }
   else { // decoding

      char phrase[ 80 ];
      strcpy( phrase, p );

      for ( char* t{ strtok( phrase, " " ) }; t; t = strtok( NULL, " " ) ) {
         if ( *( t - 2 ) == ' ' )
            cout << ' ';
         for ( int i{}; i < SIZE; ++i )
            if ( !strcmp( t, codes[ i ] ) )
               cout << char( i + ( strlen( t ) == 5 ? 22 : 65 ) );
      }
   }
   cout << endl;
}
