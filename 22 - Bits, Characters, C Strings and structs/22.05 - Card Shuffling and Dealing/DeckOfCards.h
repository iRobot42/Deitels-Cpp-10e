// Exercise 22.5: DeckOfCards.h

#include <array>

struct BitCard {
   unsigned face : 4;
   unsigned suit : 2;
   unsigned color : 1;
};

typedef BitCard Card;

class DeckOfCards {

public:

   static const int CARDS{ 52 };
   static const int FACES{ 13 };
   static const int SUITS{ 4 };
   static const int COLORS{ 2 };

   DeckOfCards();

   void shuffle();
   void deal() const;

private:

   std::array< Card, CARDS > deck;
};