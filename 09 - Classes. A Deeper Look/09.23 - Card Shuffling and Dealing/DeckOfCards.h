// Exercise 9.23: DeckOfCards.h
// Member functions defined in DeckOfCards.cpp

#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

#include "Card.h"

static const size_t DSIZE{ FSIZE * SSIZE }; // 52

class DeckOfCards {

public:

   DeckOfCards();

   void shuffle();
   Card dealCard();
   bool moreCards() const;

private:

   std::array< Card, DSIZE > deck;
   int currentCard;
};

#endif