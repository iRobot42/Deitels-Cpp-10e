// Exercise 9.24: Card.cpp
// Card class member-function definitions

#include "Card.h"

using namespace std;

Card::Card( const Face F, const Suit S ) {
   face = size_t( F );
   suit = size_t( S );
}

string Card::toString() const {
   return FACES[ face ] + " of " + SUITS[ suit ];
}

size_t Card::getFace() const { return face; }
size_t Card::getSuit() const { return suit; }