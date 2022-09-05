// Exercise 19.16: ex_19_16.cpp
// Constructing a Binary Tree

#include <iostream>
#include "Tree.h"

int main() {

   Tree< int > bst;

   std::cout << "12 integer values: ";
   for ( int i{}; i < 12; ++i ) {
      int value{};
      std::cin >> value;
      bst.insert( value );
   }

   std::cout << "\nPreorder   "; bst.preorderTraversal();
   std::cout << "\nInorder    "; bst.inorderTraversal();
   std::cout << "\nPostorder  "; bst.postorderTraversal();

   return EXIT_SUCCESS;
}
