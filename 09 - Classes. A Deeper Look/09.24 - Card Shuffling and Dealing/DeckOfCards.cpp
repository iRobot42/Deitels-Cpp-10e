// Exercise 9.24: DeckOfCards.cpp
// DeckOfCards class member-function definitions

#include <iostream>
#include <ctime>
#include <random>

#include "DeckOfCards.h"

using namespace std;

default_random_engine generator{ static_cast< unsigned >( time( 0 ) ) };

DeckOfCards::DeckOfCards() : currentCard( 0 ) {
   for ( size_t f{}; f < FSIZE; ++f )
      for ( size_t s{}; s < SSIZE; ++s )
         deck[ currentCard++ ] = Card{ Face( f ), Suit( s ) };
   currentCard = 0;
}

void DeckOfCards::shuffle() {

   uniform_int_distribution< int > uid{ currentCard, DSIZE - 1 };

   for ( int card{ currentCard }; card < DSIZE; ++card ) {

      const int RAND{ uid( generator ) };
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

void DeckOfCards::dealHand() {
   for ( auto& card : hand )
      card = dealCard();
}

bool DeckOfCards::moreCards() const {
   return currentCard < DSIZE;
}

void DeckOfCards::showHand() const {

   for ( const auto& card : hand )
      cout << card.toString() << endl;

   cout << "\nThe hand contains high card"
      << ( pair() ? ", a pair" : "" )
      << ( pairs() ? ", two pairs" : "" )
      << ( three() ? ", three of a kind" : "" )
      << ( four() ? ", four of a kind" : "" )
      << ( flush() ? ", flush" : "" )
      << ( straight() ? ", straight" : "" ) << endl;
}

bool DeckOfCards::pair() const {
   for ( size_t i{}; i < HSIZE - 1; ++i )
      for ( size_t j{ i + 1 }; j < HSIZE; ++j )
         if ( hand[ i ].getFace() == hand[ j ].getFace() )
            return true;
   return false;
}

bool DeckOfCards::pairs() const {
   array< short, FSIZE > counter{};
   bool found{};
   for ( size_t card{}; card < HSIZE; ++card )
      if ( ++counter[ hand[ card ].getFace() ] == 2 )
         if ( found ) return true;
         else found = true;
   return false;
}

bool DeckOfCards::three() const {
   array< short, FSIZE > counter{};
   for ( size_t card{}; card < HSIZE; ++card )
      if ( ++counter[ hand[ card ].getFace() ] == 3 )
         return true;
   return false;
}

bool DeckOfCards::four() const {
   array< short, FSIZE > counter{};
   for ( size_t card{}; card < HSIZE; ++card )
      if ( ++counter[ hand[ card ].getFace() ] == 4 )
         return true;
   return false;
}

bool DeckOfCards::flush() const {
   for ( size_t card{}; card < HSIZE - 1; ++card )
      if ( hand[ card ].getSuit() != hand[ card + 1 ].getSuit() )
         return false;
   return true;
}

bool DeckOfCards::straight() const {
   array< bool, FSIZE > f{};
   for ( size_t card{}; card < HSIZE; ++card )
      f[ hand[ card ].getFace() ] = true;
   for ( size_t i{}; i <= FSIZE - HSIZE; ++i )
      if ( f[ i ] && f[ i + 1 ] && f[ i + 2 ] && f[ i + 3 ] && f[ i + 4 ] )
         return true;
   return f[ 0 ] && f[ 1 ] && f[ 2 ] && f[ 3 ] && f[ 12 ];
}
