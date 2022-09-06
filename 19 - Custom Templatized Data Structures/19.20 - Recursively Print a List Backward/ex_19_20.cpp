// Exercise 19.20: ex_19_20.cpp
// Recursively Print a List Backward

#include <iostream>
#include "List.h"

int main() {

   List< int > list;
   list.push_back( 0 );
   list.push_back( 42 );
   list.push_back( 1024 );

   std::cout << list << '\n';
   list.printListBackward();

   return EXIT_SUCCESS;
}
