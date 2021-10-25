// Exercise 9.15: TicTacToe.cpp
// TicTacToe class member-function definitions

#include <iostream>
#include <random>

#include "TicTacToe.h"

using namespace std;

default_random_engine generator{ static_cast< unsigned >( time( 0 ) ) };

TicTacToe::TicTacToe() {
   for ( int row{}; row < SIZE; ++row )
      for ( int col{}; col < SIZE; ++col )
         board[ row ][ col ] = 0;
};

void TicTacToe::print() const {

   cout << endl;
   for ( int row{}; row < SIZE; ++row ) {
      for ( int col{}; col < SIZE; ++col ) {
         cout << ' ';
         if ( board[ row ][ col ] ) cout << board[ row ][ col ];
         else cout << '.';
      }
      cout << endl;
   }
   cout << endl;
}

void TicTacToe::play() {

   cout << "Welcome to tic-tac-toe game!\n"
      << "\nThe player who succeeds in placing three of their marks\n"
      << "in a horizontal, vertical, or diagonal row is the winner.\n"
      << "\nEnter two numbers in format ROW COLUMN (starting index is 0),\n"
      << "or negative number to terminate the game.\n" << endl;

   char player[ 2 ];

   for ( int i{}; i < 2; ++i ) do {
      cout << "Player " << i + 1 << " ([h]uman or [c]omputer): ";
      cin >> player[ i ];
   } while ( player[ i ] != 'h' && player[ i ] != 'c' );

   cout << "\nGood luck!" << endl;

   bool current{ false };
   State state;

   do {
      print();
      current = !current;
      state = turn( current, player[ !current ] );
   } while ( state == State::CONTINUE );

   print();
   cout << "Game over. ";
   if ( state == State::DRAW ) cout << "Draw." << endl;
   else cout << "Player " << ( current ? '1' : '2' ) << " wins!" << endl;
}

const State TicTacToe::turn( const bool& CUR, const char& WHO ) {

   int r, c;
   uniform_int_distribution< int > uid{ 0, SIZE - 1 };

   if ( WHO == 'h' )
      do {
         cout << "Player " << ( CUR ? '1' : '2' ) << ": ";
         cin >> r; if ( r < 0 ) exit( 0 );
         cin >> c;
      } while ( r < 0 || r >= SIZE || c < 0 || c >= SIZE || board[ r ][ c ] );
   else {
      do { // no strategy, just random. TODO: improve AI logic
         r = uid( generator );
         c = uid( generator );
      } while ( board[ r ][ c ] ); // lmao
      cout << "Player " << ( CUR ? '1' : '2' ) << ": " << r << ' ' << c << endl;
   }

   board[ r ][ c ] = ( CUR ? 1 : 2 );

   return check( r, c ) ? State::WIN
             : ( full() ? State::DRAW
                        : State::CONTINUE );
}

const bool TicTacToe::check( const int& R, const int& C ) const {

   for ( int c{}; c < SIZE - 1; ++c ) {
      if ( !board[ R ][ c ] || board[ R ][ c ] != board[ R ][ c + 1 ] ) break;
      if ( c == SIZE - 2 ) return true;
   }

   for ( int r{}; r < SIZE - 1; ++r ) {
      if ( !board[ r ][ C ] || board[ r ][ C ] != board[ r + 1 ][ C ] ) break;
      if ( r == SIZE - 2 ) return true;
   }

   if ( R == C ) for ( int i{}; i < SIZE - 1; ++i ) {
      if ( !board[ i ][ i ] || board[ i ][ i ] != board[ i + 1 ][ i + 1 ] ) break;
      if ( i == SIZE - 2 ) return true;
   }

   if ( R + C == SIZE - 1 ) for ( int r{}, c{ SIZE - 1 }; c >= 0; ++r, --c ) {
      if ( !board[ r ][ c ] || board[ r ][ c ] != board[ r + 1 ][ c - 1 ] ) break;
      if ( r == SIZE - 2 ) return true;
   }

   return false;
}

const bool TicTacToe::full() const {
   for ( int row{}; row < SIZE; ++row )
      for ( int col{}; col < SIZE; ++col )
         if ( !board[ row ][ col ] ) return false;
   return true;
}
