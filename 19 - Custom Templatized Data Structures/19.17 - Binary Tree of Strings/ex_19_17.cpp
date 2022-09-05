// Exercise 19.17: ex_19_17.cpp
// Binary Tree of Strings

#include <iostream>
#include <sstream>
#include "Tree.h"

int main() {

   Tree< std::string > bst;
   std::string text, word;
   std::cout << "String: ";
   std::getline( std::cin, text );

   std::istringstream iss{ text };
   while ( iss >> word )
      bst.insert( word );

   std::cout << "\nPreorder   "; bst.preorderTraversal();
   std::cout << "\nInorder    "; bst.inorderTraversal();
   std::cout << "\nPostorder  "; bst.postorderTraversal();

   return EXIT_SUCCESS;
}
