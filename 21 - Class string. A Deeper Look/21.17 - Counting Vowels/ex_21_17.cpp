// Exercise 21.17: ex_21_17.cpp
// Counting Vowels

#include <iostream>
#include <string>
using namespace std;

int main() {

   string sentence;

   cout << "Sentence: ";
   getline( cin, sentence );

   size_t frequency[ 5 ]{}; // a e i o u

   for ( const auto CHAR : sentence )
      switch ( tolower( CHAR ) ) {
      case 'a': frequency[ 0 ]++; break;
      case 'e': frequency[ 1 ]++; break;
      case 'i': frequency[ 2 ]++; break;
      case 'o': frequency[ 3 ]++; break;
      case 'u': frequency[ 4 ]++; break;
      }

   size_t total{};

   for ( const auto NUMBER : frequency )
      total += NUMBER;

   cout << "Vowels: " << total
      << "\na: " << frequency[ 0 ]
      << "\ne: " << frequency[ 1 ]
      << "\ni: " << frequency[ 2 ]
      << "\no: " << frequency[ 3 ]
      << "\nu: " << frequency[ 4 ] << endl;

   return EXIT_SUCCESS;
}
