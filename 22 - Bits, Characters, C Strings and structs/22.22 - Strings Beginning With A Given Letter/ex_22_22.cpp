// Exercise 22.22: ex_22_22.cpp
// Strings Beginning With A Given Letter

#include <iostream>
using namespace std;

int main() {

   const int TOTAL{ 5 };
   const int SIZE{ 80 };

   cout << "Enter " << TOTAL << " strings...\n" << endl;

   char str[ TOTAL ][ SIZE ]{};
   for ( int i{}; i < TOTAL; ++i ) {
      cout << i + 1 << ": ";
      cin.getline( &str[ i ][ 0 ], SIZE );
   }
   cout << endl;

   char chr{};
   while ( !isalpha( chr ) ) {
      cout << "Letter: ";
      cin >> chr;
   }

   cout << "\nStrings beginning with '" << chr << "':";

   for ( int i{}; i < TOTAL; ++i )
      if ( tolower( str[ i ][ 0 ] ) == tolower( chr ) )
         cout << ' ' << i + 1;
   cout << endl;

   return EXIT_SUCCESS;
}
