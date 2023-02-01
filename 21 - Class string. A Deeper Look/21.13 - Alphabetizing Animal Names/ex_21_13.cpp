// Exercise 21.13: ex_21_13.cpp
// Alphabetizing Animal Names

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

inline void print( const vector< string >& ANIMALS ) {
   for ( const auto& ANIMAL : ANIMALS )
      cout << ANIMAL << ' ';
   cout << endl;
}

bool compare( string s1, string s2 ) {
   for ( auto& c : s1 )
      c = toupper( c );
   for ( auto& c : s2 )
      c = toupper( c );
   return s1 < s2; // s1.compare( s2 ) < 0;
}

int main() {

   vector< string > animals{ "Fox", "dog", "rabbit", "squirrel", "raccoon",
      "frog", "fish", "parrot", "beaver", "rooster", "cat" };
   print( animals );

   sort( animals.begin(), animals.end(), compare );
   print( animals );

   return EXIT_SUCCESS;
}
