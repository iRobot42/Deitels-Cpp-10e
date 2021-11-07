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
   void dealHand();
   bool moreCards() const;
   void showHand() const;

private:

   std::array< Card, DSIZE > deck;
   std::array< Card, HSIZE > hand;
   int currentCard;

   bool pair() const;
   bool pairs() const;
   bool three() const;
   bool four() const;
   bool flush() const;
   bool straight() const;
};

#endif