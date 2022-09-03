// Exercise 19.12: ex_19_12.cpp
// Infix-to-Postfix Conversion

#include <iostream>
#include <string>
#include "Stack.h"

std::string convertToPostfix( const std::string& );
bool isOperator( const char );
bool precedence( const char, const char );

int main() {

   std::string infix;

   std::cout << "Infix arithmetic expression: ";
   std::getline( std::cin, infix ); // assuming correct input

   const std::string POSTFIX{ convertToPostfix( infix ) };
   std::cout << "Converted to postfix notation: " << POSTFIX;

   return EXIT_SUCCESS;
}

std::string convertToPostfix( const std::string& INFIX ) {
   if ( INFIX.empty() ) return "";

   Stack< char > stack;
   std::string postfix;

   for ( const auto& CHAR : INFIX ) {
      if ( isdigit( CHAR ) )
         postfix.push_back( CHAR );
      else if ( CHAR == '(' )
         stack.push( CHAR );
      else if ( CHAR == ')' ) {
         while ( isOperator( stack.top() ) && stack.top() != '(' )
            postfix.push_back( stack.pop() );
         stack.pop();
      }
      else if ( isOperator( CHAR ) ) {
         while ( !stack.empty() && isOperator( stack.top() )
                 && precedence( stack.top(), CHAR ) )
            postfix.push_back( stack.pop() );
         stack.push( CHAR );
      }
   }
   while ( !stack.empty() )
      postfix.push_back( stack.pop() );

   return postfix;
}

bool isOperator( const char C ) {
   static const std::string OP{ "+-*/%^" };
   return OP.find( C ) != std::string::npos;
}

bool precedence( const char L, const char R ) {
   return ( L == '+' || L == '-' ) && ( R == '+' || R == '-' )
      || ( L == '*' || L == '/' || L == '%' ) && R != '^' || L == '^';
}
