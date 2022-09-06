// Exercise 19.21: ex_19_21.cpp
// Recursively Search a List

#include <iostream>
#include "ForwardList.h"

int main() {

   ForwardList< int > list;
   list.push_back( -1 ); list.push_back( 0 ); list.push_back( 1 );
   list.push_back( 8 ); list.push_back( 42 ); list.push_back( 1024 );

   std::cout << "Test list: " << list << "\nSearch: ";
   int value;
   std::cin >> value;

   int* found{ list.searchList( value ) };
   if ( !found ) std::cout << "Value not found";
   else std::cout << "Value found at 0x" << found << " (" << *found << ')';

   return EXIT_SUCCESS;
}
