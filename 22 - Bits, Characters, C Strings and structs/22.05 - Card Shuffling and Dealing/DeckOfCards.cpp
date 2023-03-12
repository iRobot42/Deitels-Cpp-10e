// Exercise 22.5: DeckOfCards.cpp

#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

#include "DeckOfCards.h"

using namespace std;

DeckOfCards::DeckOfCards() {

   for ( size_t i{}; i < deck.size(); ++i ) {
      deck[ i ].face = i % FACES;
      deck[ i ].suit = i / FACES;
      deck[ i ].color = i / ( FACES * COLORS );
   }

   srand( static_cast< size_t >( time( nullptr ) ) );
}

void DeckOfCards::shuffle() {

   for ( size_t i{}; i < deck.size(); ++i ) {
      int j{ rand() % CARDS };
      Card temp = deck[ i ];
      deck[ i ] = deck[ j ];
      deck[ j ] = temp;
   }
}

void DeckOfCards::deal() const {

   static string color[ COLORS ]{ "Red", "Black" };
   static string suit[ SUITS ]{ "Hearts", "Diamonds", "Clubs", "Spades" };
   static string face[ FACES ]{ "Ace", "Deuce", "Three", "Four", "Five",
      "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };

   for ( size_t k1{}, k2{ k1 + CARDS / 2 }; k1 < CARDS / 2; ++k1, ++k2 )
      cout << left  << setw( 6 )  << color[ deck[ k1 ].color ]
           << right << setw( 6 )  << face[ deck[ k1 ].face ] << " of "
           << left  << setw( 14 ) << suit[ deck[ k1 ].suit ]
                    << setw( 6 )  << color[ deck[ k2 ].color ]
           << right << setw( 6 )  << face[ deck[ k2 ].face ] << " of "
                                  << suit[ deck[ k2 ].suit ] << endl;
}