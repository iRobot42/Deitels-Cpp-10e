// Exercise 9.24: ex_09_24.cpp
// Card Shuffling and Dealing

#include "Hand.h"

using namespace std;

int main() {

   DeckOfCards Deck;
   Deck.shuffle();

   Hand Player{ Deck };
   Player.show();

   return 0;
}
