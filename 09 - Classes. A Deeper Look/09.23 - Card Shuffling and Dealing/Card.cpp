// Exercise 9.23: Card.cpp
// Card class member-function definitions

#include "Card.h"

using namespace std;

Card::Card( const FACE& F, const SUIT& S ) {
   face = size_t( F );
   suit = size_t( S );
}

string Card::toString() const {
   return FACES[ face ] + " of " + SUITS[ suit ];
}