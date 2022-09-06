// Exercise 19.24: ex_19_24.cpp
// Printing Trees

#include <iostream>
#include "Tree.h"

int main() {

   srand( static_cast< unsigned >( time( NULL ) ) );

   Tree< int > bst;
   for ( int i{}; i < 15; ++i )
      bst.insert( 1 + rand() % 99 );

   bst.output();

   return EXIT_SUCCESS;
}
