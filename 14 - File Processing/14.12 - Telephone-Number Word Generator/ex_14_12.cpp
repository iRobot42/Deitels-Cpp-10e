// Exercise 14.12: ex_14_12.cpp
// Telephone-Number Word Generator

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool correct( string& );
void generate( const string& );

int main() {

   string phone;

   do {
      cout << "Phone number: ";
      cin >> phone;
   } while ( !correct( phone ) );

   generate( phone );

   return 0;
}

bool correct( string& number ) {

   string digits;

   for ( const auto& symbol : number )
      if ( symbol == '0' || symbol == '1' ) {
         cout << "The number contains 0 or 1\n";
         return false;
      }
      else if ( isdigit( symbol ) )
         digits += symbol;

   if ( digits.size() != 7 ) {
      cout << "The number must be seven digits\n";
      return false;
   }

   number = digits;
   return true;
}

void generate( const string& number ) {

   string filename{ number + ".txt" };
   ofstream file( filename );
   if ( !file ) exit( EXIT_FAILURE );

   string letters[]{ "", "",
      "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ" };

   for ( const auto& l1 : letters[ number[ 0 ] - 48 ] )
      for ( const auto& l2 : letters[ number[ 1 ] - 48 ] )
         for ( const auto& l3 : letters[ number[ 2 ] - 48 ] )
            for ( const auto& l4 : letters[ number[ 3 ] - 48 ] )
               for ( const auto& l5 : letters[ number[ 4 ] - 48 ] )
                  for ( const auto& l6 : letters[ number[ 5 ] - 48 ] )
                     for ( const auto& l7 : letters[ number[ 6 ] - 48 ] )
                        file << l1 << l2 << l3 << l4 << l5 << l6 << l7 << ' ';

   cout << "Saved: " << filename << endl;
   file.close();
}
