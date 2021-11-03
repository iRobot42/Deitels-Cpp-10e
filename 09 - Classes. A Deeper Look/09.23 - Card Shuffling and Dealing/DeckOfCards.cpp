// Exercise 9.23: DeckOfCards.cpp
// DeckOfCards class member-function definitions

#include <ctime>
#include <random>

#include "DeckOfCards.h"

using namespace std;

default_random_engine generator{ static_cast< unsigned >( time( 0 ) ) };

DeckOfCards::DeckOfCards() : currentCard( 0 ) {
   for ( size_t f{}; f < FSIZE; ++f )
      for ( size_t s{}; s < SSIZE; ++s )
         deck[ currentCard++ ] = Card{ FACE( f ), SUIT( s ) };
   currentCard = 0;
}

void DeckOfCards::shuffle() {

   uniform_int_distribution< size_t > uid{ 0, DSIZE - 1 };

   for ( size_t card{}; card < DSIZE; ++card ) {
      
      const size_t RAND{ uid( generator ) };
      const Card TEMP{ deck[ card ] };
      
      deck[ card ] = deck[ RAND ];
      deck[ RAND ] = TEMP;
   }
}

Card DeckOfCards::dealCard() {
   if ( moreCards() )
      return deck[ currentCard++ ];
   else throw( "invalid card" );
}

bool DeckOfCards::moreCards() const {
   return currentCard < DSIZE;
}