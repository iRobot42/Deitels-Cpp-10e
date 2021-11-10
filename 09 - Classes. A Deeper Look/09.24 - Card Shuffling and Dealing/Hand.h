// Exercise 9.24: Hand.h
// Member functions defined in Hand.cpp

#ifndef HAND_H
#define HAND_H

#include "DeckOfCards.h"

class Hand {

public:

   explicit Hand( DeckOfCards& );

   void deal( DeckOfCards& );
   void show() const;

private:

   std::array< Card, HSIZE > hand;

   bool pair() const;
   bool pairs() const;
   bool three() const;
   bool four() const;
   bool flush() const;
   bool straight() const;
};

#endif