// Exercise 19.23: ex_19_23.cpp
// Level-Order Binary Tree Traversal

#include <iostream>
#include "Tree.h"

int main() {

   Tree< char > bst;
   std::cout << "5-char word: ";
   for ( int i{}; i < 5; ++i )
      bst.insert( std::cin.get() );

   std::cout << "\nLevel-order traversal: ";
   bst.levelOrder();

   return EXIT_SUCCESS;
}
