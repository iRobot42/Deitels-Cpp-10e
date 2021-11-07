// Exercise 9.24: Card.h
// Member functions defined in Card.cpp

#ifndef CARD_H
#define CARD_H

#include <array>
#include <string>

static const size_t FSIZE{ 13 };
static const size_t SSIZE{ 4 };

enum class Face{ Deuce, Three, Four, Five, Six, Seven, Eight, Nine, Ten,
   Jack, Queen, King, Ace };
enum class Suit{ Clubs, Diamonds, Hearts, Spades };

static const std::array< std::string, FSIZE > FACES{
   "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
   "Jack", "Queen", "King", "Ace" };
static const std::array< std::string, SSIZE > SUITS{
   "Clubs", "Diamonds", "Hearts", "Spades" };

class Card {

public:

   explicit Card( const Face = Face( 0 ), const Suit = Suit( 0 ) );

   std::string toString() const;

   size_t getFace() const;
   size_t getSuit() const;

private:

   size_t face;
   size_t suit;
};

#endif