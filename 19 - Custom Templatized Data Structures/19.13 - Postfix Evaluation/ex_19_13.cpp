// Exercise 19.13: ex_19_13.cpp
// Postfix Evaluation

#include <iostream>
#include <string>
#include <cmath>
#include "Stack.h"

int evaluatePostfixExpression( const std::string& );
int calculate( const int, const int, const char );

int main() {

   std::string postfix;
   std::cout << "Postfix expression: ";
   std::getline( std::cin, postfix );
   std::cout << "Calculated value: " << evaluatePostfixExpression( postfix );

   return EXIT_SUCCESS;
}

int evaluatePostfixExpression( const std::string& POSTFIX ) {

   Stack< int > stack;
   for ( const auto& CHAR : POSTFIX )
      if ( isdigit( CHAR ) ) stack.push( CHAR - '0' );
      else if ( CHAR == ' ' ) continue;
      else { // operator
         const int X{ stack.pop() }, Y{ stack.pop() };
         stack.push( calculate( Y, X, CHAR ) );
      }
   return stack.pop();
}

int calculate( const int OP1, const int OP2, const char OPERATOR ) {

   switch ( OPERATOR ) {
   case '+': return OP1 + OP2;
   case '-': return OP1 - OP2;
   case '*': return OP1 * OP2;
   case '/': if ( OP2 ) return OP1 / OP2; else exit( EXIT_FAILURE );
   case '%': if ( OP2 ) return OP1 % OP2; else exit( EXIT_FAILURE );
   case '^': return static_cast< int >( pow( OP1, OP2 ) );
   }
   std::cerr << "Invalid operator";
   exit( EXIT_FAILURE );
}
