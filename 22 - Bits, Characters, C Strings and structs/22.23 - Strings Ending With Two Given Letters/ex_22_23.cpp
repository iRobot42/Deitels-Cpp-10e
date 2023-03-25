// Exercise 22.23: ex_22_23.cpp
// Strings Ending With Two Given Letters

#include <cstring>
#include <iostream>
using namespace std;

int main() {

   const int TOTAL{ 6 };
   const int SIZE{ 80 };

   cout << "Enter " << TOTAL << " strings...\n" << endl;

   char str[ TOTAL ][ SIZE ]{};
   for ( int i{}; i < TOTAL; ++i ) {
      cout << i + 1 << ": ";
      cin.getline( &str[ i ][ 0 ], SIZE );
   }
   cout << endl;

   char comb[ 2 + 1 ];
   do {
      cout << "Two-letter combination: ";
      cin >> comb;
   } while ( !isalpha( comb[ 0 ] ) && !isalpha( comb[ 1 ] ) );
   comb[ 2 ] = '\0';

   cout << "\nStrings ending with \"" << comb << "\":";
   for ( int i{}; i < TOTAL; ++i ) {
      const size_t LENGTH{ strlen( str[ i ] ) };
      if ( !strcmp( &str[ i ][ LENGTH - 2 ], comb ) )
         cout << ' ' << i + 1;
   }
   cout << endl;

   return EXIT_SUCCESS;
}
