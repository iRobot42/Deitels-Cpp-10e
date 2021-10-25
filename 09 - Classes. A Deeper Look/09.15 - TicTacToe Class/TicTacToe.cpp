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

   for ( int i{}; i < 2; ++i )
      do {
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

const State TicTacToe::turn( const bool CUR, const char WHO ) {

   int r, c;
   uniform_int_distribution< int > uid{ 0, 2 };

   if ( WHO == 'h' )
      do {
         cout << "Player " << ( CUR ? '1' : '2' ) << ": ";
         cin >> r; if ( r < 0 ) exit( 0 );
         cin >> c;
      } while ( r < 0 || r >= SIZE || c < 0 || c >= SIZE || board[ r ][ c ] );
   else {
      do { // no strategy, just randomizer. TODO: improve AI logic
         r = uid( generator );
         c = uid( generator );
      } while ( board[ r ][ c ] );
      cout << "Player " << ( CUR ? '1' : '2' ) << ": " << r << ' ' << c << endl;
   }

   board[ r ][ c ] = ( CUR ? 1 : 2 );

   for ( int i{}; i < SIZE - 1; ++i ) {
      if ( !board[ r ][ i ] || board[ r ][ i ] != board[ r ][ i + 1 ] ) break;
      if ( i == SIZE - 2 ) return State::WIN;
   }

   for ( int i{}; i < SIZE - 1; ++i ) {
      if ( !board[ i ][ c ] || board[ i ][ c ] != board[ i + 1 ][ c ] ) break;
      if ( i == SIZE - 2 ) return State::WIN;
   }

   if ( r == c ) for ( int i{}; i < SIZE - 1; ++i ) {
      if ( !board[ i ][ i ] || board[ i ][ i ] != board[ i + 1 ][ i + 1 ] ) break;
      if ( i == SIZE - 2 ) return State::WIN;
   }

   if ( r + c == SIZE - 1 ) for ( int i{}, j{ SIZE - 1 }; j >= 0; ++i, --j ) {
      if ( !board[ i ][ j ] || board[ i ][ j ] != board[ i + 1 ][ j - 1 ] ) break;
      if ( i == SIZE - 2 ) return State::WIN;
   }

   for ( int row{}; row < SIZE; ++row )
      for ( int col{}; col < SIZE; ++col )
         if ( !board[ row ][ col ] ) return State::CONTINUE;

   return State::DRAW;
}