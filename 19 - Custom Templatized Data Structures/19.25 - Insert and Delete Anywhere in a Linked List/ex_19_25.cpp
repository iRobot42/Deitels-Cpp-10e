// Exercise 19.25: ex_19_25.cpp
// Insert/Delete Anywhere in a Linked List

#include <iostream>
#include "ForwardList.h"

int main() {

   srand( static_cast< unsigned >( time( NULL ) ) );

   ForwardList< int > list;
   for ( int i{}; i < 5; ++i )
      list.push_back( 1 + rand() % 99 );
   std::cout << "List initialized: " << list;

   list.insert( 1, 42 );
   std::cout << "\n42 inserted at 1: " << list;

   list.erase( 1 );
   std::cout << "\nElement 1 erased: " << list;

   return EXIT_SUCCESS;
}
