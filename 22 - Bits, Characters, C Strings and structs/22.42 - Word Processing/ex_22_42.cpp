// Exercise 22.42: ex_22_42.cpp
// Word Processing

#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <iostream>
using namespace std;

int main() {

   const char test[]{ "\tLorem ipsum dolor sit amet, consectetur adipiscing elit, "
      "sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut "
      "enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut "
      "aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit "
      "in voluptate velit esse cillum dolore eu fugiat nulla pariatur.\n"
      "\tExcepteur sint occaecat cupidatat non proident, sunt in culpa qui "
      "officia deserunt mollit anim id est laborum.\n" };

   cout << "ORIGINAL:\n\n" << test << "\n\nFORMATTED:\n\n";

   const int WIDTH{ 65 }, SIZE{ sizeof( test ) / sizeof( char ) };
   int width{ WIDTH };

   for ( int i{}; i < SIZE; i += width ) {

      char line[ WIDTH + 1 ]{};
      line[ WIDTH ] = '\0';

      while ( isspace( test[ i ] ) ) i++;
      width = WIDTH;

      for ( int j{}; j < width; ++j )
         switch ( test[ i + j ] ) {
            case '\n':
            case '\0': width = ++j; break;
         }
      if ( width == WIDTH )
         while ( isgraph( test[ i + --width ] ) );

      int spaces{ WIDTH - width + 1 };

      strncpy( line, test + i, width );
      cout << line << endl;

      // TODO: justification
   }

   return EXIT_SUCCESS;
}
