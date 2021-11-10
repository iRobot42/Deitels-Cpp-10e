// Exercise 9.24: DeckOfCards.h
// Member functions defined in DeckOfCards.cpp

#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

#include "Card.h"

static const size_t DSIZE{ FSIZE * SSIZE }; // 52
static const size_t HSIZE{ 5 };

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
