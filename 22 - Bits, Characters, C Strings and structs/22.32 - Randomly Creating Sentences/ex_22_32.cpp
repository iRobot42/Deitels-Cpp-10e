// Exercise 22.32: ex_22_32.cpp
// Randomly Creating Sentences

#include <cstring>
#include <iostream>
#include <random>
using namespace std;

int main() {

   default_random_engine generator{ random_device{}() };
   uniform_int_distribution< int > number( 0, 4 );

   const char* article[]{ "the", "a", "one", "some", "any" };
   const char* noun[]{ "boy", "girl", "dog", "town", "car" };
   const char* verb[]{ "drove", "jumped", "ran", "walked", "skipped" };
   const char* preposition[]{ "to", "from", "over", "under", "on" };

   for ( int i{}; i < 20; ++i ) {

      char sentence[ 80 ]{};

      strcat_s( sentence, article[ number( generator ) ] );
      *sentence = toupper( *sentence );
      strcat_s( sentence, " " );
      strcat_s( sentence, noun[ number( generator ) ] );
      strcat_s( sentence, " " );
      strcat_s( sentence, verb[ number( generator ) ] );
      strcat_s( sentence, " " );
      strcat_s( sentence, preposition[ number( generator ) ] );
      strcat_s( sentence, " " );
      strcat_s( sentence, article[ number( generator ) ] );
      strcat_s( sentence, " " );
      strcat_s( sentence, noun[ number( generator ) ] );
      strcat_s( sentence, "." );

      cout << sentence << endl;
   }

   return EXIT_SUCCESS;
}
