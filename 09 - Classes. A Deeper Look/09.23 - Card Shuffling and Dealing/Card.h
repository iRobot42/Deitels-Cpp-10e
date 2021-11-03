// Exercise 9.23: Card.h
// Member functions defined in Card.cpp

#ifndef CARD_H
#define CARD_H

#include <array>
#include <string>

static const size_t FSIZE{ 13 };
static const size_t SSIZE{ 4 };

const enum class FACE{ Deuce, Three, Four, Five, Six, Seven, Eight, Nine, Ten,
   Jack, Queen, King, Ace };
const enum class SUIT{ Clubs, Diamonds, Hearts, Spades };

static const std::array< std::string, FSIZE > FACES{
   "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
   "Jack", "Queen", "King", "Ace" };
static const std::array< std::string, SSIZE > SUITS{
   "Clubs", "Diamonds", "Hearts", "Spades" };

class Card {

public:

   explicit Card( const FACE& = FACE( 0 ), const SUIT& = SUIT( 0 ) );

   std::string toString() const;

private:

   size_t face;
   size_t suit;
};

#endif