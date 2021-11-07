// Exercise 9.24: ex_09_24.cpp
// Card Shuffling and Dealing

#include <iomanip>
#include <iostream>

#include "DeckOfCards.h"

using namespace std;

int main() {

   DeckOfCards Deck;

   Deck.shuffle();
   Deck.dealHand();
   Deck.showHand();

   return 0;
}
