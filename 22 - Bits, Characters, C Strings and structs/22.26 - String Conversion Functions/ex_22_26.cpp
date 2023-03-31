// Exercise 22.26: ex_22_26.cpp
// String Conversion Functions

#include <iostream>
#include <sstream>
using namespace std;

double        af    ( const char* );
int           ai    ( const char* );
long          al    ( const char* );
double        strd  ( const char*, char** );
long          strl  ( const char*, char**, int );
unsigned long strul ( const char*, char**, int );

int main() {

   cout << "af( \"-3.14\" ): " << af( "-3.14" )
      << "\naf( \" +.01\" ): " << af( " +.01" )
      << "\naf( \"seven\" ): " << af( "seven" )
      << '\n'
      << "\nai( \" 42 \" ): " << ai( " 42 " )
      << "\nai( \"-1.1\" ): " << ai( "-1.1" )
      << "\nai( \"!@#$\" ): " << ai( "!@#$" )
      << '\n'
      << "\nal( \"2000000000\" ): " << al( "2000000000" )
      << "\nal( \"12345.6789\" ): " << al( "12345.6789" )
      << "\nal( \"fahrenheit\" ): " << al( "fahrenheit" ) << endl;

   return EXIT_SUCCESS;
}

double af( const char* nPtr ) {
   istringstream iss( nPtr );
   double number;
   iss >> number;
   return number;
}

int ai( const char* nPtr ) {
   istringstream iss( nPtr );
   int number;
   iss >> number;
   return number;
}

long al( const char* nPtr ) {
   istringstream iss( nPtr );
   long number( *nPtr );
   iss >> number;
   return number;
}

// TODO

double strd( const char* nPtr, char** endPtr ) {
   return {};
}

long strl( const char* nPtr, char** endPtr, int base ) {
   return {};
}

unsigned long strul( const char* nPtr, char** endPtr, int base ) {
   return {};
}
