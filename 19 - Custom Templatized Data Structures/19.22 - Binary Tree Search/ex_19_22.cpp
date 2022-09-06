// Exercise 19.22: ex_19_22.cpp
// Binary Tree Search

#include <iostream>
#include "Tree.h"

int main() {

   Tree< int > bst;
   bst.insert( 8 );  bst.insert( 0 ); bst.insert( 42 );
   bst.insert( -1 ); bst.insert( 1 ); bst.insert( 1024 );

   std::cout << "Test tree: ";
   bst.inorderTraversal();
   std::cout << "\nSearch: ";
   int value;
   std::cin >> value;

   int* found{ bst.search( value ) };
   if ( !found ) std::cout << "Value not found";
   else std::cout << "Value found at " << found << " (" << *found << ')';

   return EXIT_SUCCESS;
}
