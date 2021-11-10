// Exercise 9.24: Hand.cpp
// Hand class member-function definitions

#include <iostream>

#include "Hand.h"

using namespace std;

Hand::Hand( DeckOfCards& D ) {
   deal( D );
}

void Hand::deal( DeckOfCards& D ) {
   for ( auto& card : hand )
      card = D.dealCard();
}

void Hand::show() const {

   for ( const auto& card : hand )
      cout << card.toString() << endl;

   cout << "\nThe hand contains high card"
      << ( pair() ? ", a pair" : "" )
      << ( pairs() ? ", two pairs" : "" )
      << ( three() ? ", three of a kind" : "" )
      << ( four() ? ", four of a kind" : "" )
      << ( flush() ? ", flush" : "" )
      << ( straight() ? ", straight" : "" ) << endl;
}

bool Hand::pair() const {
   for ( size_t i{}; i < HSIZE - 1; ++i )
      for ( size_t j{ i + 1 }; j < HSIZE; ++j )
         if ( hand[ i ].getFace() == hand[ j ].getFace() )
            return true;
   return false;
}

bool Hand::pairs() const {
   array< short, FSIZE > counter{};
   bool found{};
   for ( size_t card{}; card < HSIZE; ++card )
      if ( ++counter[ hand[ card ].getFace() ] == 2 )
         if ( found ) return true;
         else found = true;
   return false;
}

bool Hand::three() const {
   array< short, FSIZE > counter{};
   for ( size_t card{}; card < HSIZE; ++card )
      if ( ++counter[ hand[ card ].getFace() ] == 3 )
         return true;
   return false;
}

bool Hand::four() const {
   array< short, FSIZE > counter{};
   for ( size_t card{}; card < HSIZE; ++card )
      if ( ++counter[ hand[ card ].getFace() ] == 4 )
         return true;
   return false;
}

bool Hand::flush() const {
   for ( size_t card{}; card < HSIZE - 1; ++card )
      if ( hand[ card ].getSuit() != hand[ card + 1 ].getSuit() )
         return false;
   return true;
}

bool Hand::straight() const {
   array< bool, FSIZE > f{};
   for ( size_t card{}; card < HSIZE; ++card )
      f[ hand[ card ].getFace() ] = true;
   for ( size_t i{}; i <= FSIZE - HSIZE; ++i )
      if ( f[ i ] && f[ i + 1 ] && f[ i + 2 ] && f[ i + 3 ] && f[ i + 4 ] )
         return true;
   return f[ 0 ] && f[ 1 ] && f[ 2 ] && f[ 3 ] && f[ 12 ];
}