// Exercise 22.41: ex_22_41.cpp
// Text Analysis

#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;

void part_a( const char* );
void part_b( const char* );
void part_c( const char* );

int main() {

   const char str[]{ "To be, or not to be: that is the question:\n"
                     "Whether 'tis nobler in the mind to suffer" };

   cout << str << endl;

   part_a( str );
   part_b( str );
   part_c( str );

   //cout << endl << str << endl;

   return EXIT_SUCCESS;
}

void part_a( const char* s ) {

   const int LETTERS{ 26 };
   int frequency[ LETTERS ]{};

   for ( s; *s; ++s )
      frequency[ tolower( *s ) - 'a' ]++;

   cout << "\nFrequency of letters\n" << string( 20, '-' ) << endl;
   for ( int i{}; i < LETTERS; ++i )
      if ( frequency[ i ] )
         cout << char( 'a' + i ) << ": " << frequency[ i ] << endl;
}

void part_b( const char* s ) {

   const int WORD{ 20 }, TEXT{ 100 };
   const char delim[]{ " ,.:;!?\"\n\t" };

   char copy[ TEXT ];
   memcpy( copy, s, TEXT );

   int occurences[ WORD ]{};
   char* token{ strtok( copy, delim ) };

   while ( token ) {
      occurences[ strlen( token ) ]++;
      token = strtok( NULL, delim );
   }

   cout << "\nWord length\tOccurences\n" << string( 26, '-' ) << endl;
   for ( int i{}; i < WORD; ++i )
      if ( occurences[ i ] )
         cout << i << "\t\t" << occurences[ i ] << endl;
}

void part_c( const char* s ) {

   const int WORD{ 20 }, TEXT{ 100 }, WORDS{ 50 };
   const char delim[]{ " ,.:;!?\"\n\t" };

   char copy[ TEXT ];
   memcpy( copy, s, TEXT );

   char words[ WORDS ][ WORD ]{};
   int occurences[ WORDS ]{}, w{};
   char* token{ strtok( copy, delim ) };

   while ( token ) {
      *token = tolower( *token );
      bool found{};
      for ( int i{}; i < w; ++i )
         if ( !memcmp( token, words[ i ], strlen( token ) ) ) {
            found = true;
            occurences[ i ]++;
            break;
         }
      if ( !found ) {
         memcpy( words[ w ], token, WORD );
         occurences[ w++ ]++;
      }
      token = strtok( NULL, delim );
   }

   cout << endl << left << setw( WORD ) << "Word" << " Occurences\n"
      << string( WORD + 11, '-' ) << endl;
   for ( int i{}; i < w; ++i )
      cout << setw( WORD ) << words[ i ] << ' ' <<  occurences[ i ] << endl;
}
