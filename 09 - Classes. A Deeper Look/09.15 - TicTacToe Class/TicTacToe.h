// Exercise 9.15: TicTacToe.h
// Member functions defined in TicTacToe.cpp

#ifndef TICTACTOE_H
#define TICTACTOE_H

static const size_t SIZE{ 3 };
enum class State { CONTINUE, WIN, DRAW };

class TicTacToe {

public:

   TicTacToe();

   void play();
   void print() const;

private:

   int board[ SIZE ][ SIZE ]; // TODO: 3D

   const State turn( const bool, char );
};

#endif