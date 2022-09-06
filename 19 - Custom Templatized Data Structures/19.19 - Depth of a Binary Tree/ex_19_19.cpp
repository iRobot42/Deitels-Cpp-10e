// Exercise 19.19: ex_19_19.cpp
// Depth of a Binary Tree

#include <iostream>
#include "Tree.h"

template< typename Type >
int depth( const Tree< Type >& TREE ) { return TREE.calculateDepth(); }

int main() {

   Tree< char > bst;
   std::cout << "5 char values: ";
   for ( int i{}; i < 5; ++i ) {
      char c;
      std::cin >> c;
      bst.insert( c );
   }

   std::cout << "\nThe tree has " << depth( bst ) << " level(s)";

   return EXIT_SUCCESS;
}
