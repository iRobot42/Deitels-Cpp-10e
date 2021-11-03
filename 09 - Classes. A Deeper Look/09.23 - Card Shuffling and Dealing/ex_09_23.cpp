// Exercise 9.23: ex_09_23.cpp
// Card Shuffling and Dealing

#include <iomanip>
#include <iostream>

#include "DeckOfCards.h"

using namespace std;

int main() {

   DeckOfCards Deck;

   Deck.shuffle();

   cout << left;
   for ( size_t i{ 1 }; i <= DSIZE; ++i ) {
      cout << setw( 20 ) << Deck.dealCard().toString();
      if ( !( i % 4 ) ) cout << endl;
   }

   try {
      cout << Deck.dealCard().toString() << endl;
   }
   catch ( const char* ex ) {
      cerr << "\nException: " << ex << endl;
   }

   return 0;
}
