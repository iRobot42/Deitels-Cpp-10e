// Exercise 19.26: ex_19_26.cpp
// List and Queues without Tail Pointers

#include <iostream>
#include "ForwardList.h"

int main() {

   ForwardList< short > list;

   list.push_back( 2 );
   list.push_front( 1 );
   list.push_back( 3 );
   std::cout << "List initialized  " << list;

   list.pop_front();
   std::cout << "\nAfter pop_front   " << list;

   list.pop_back();
   std::cout << "\nFirst pop_back    " << list;

   list.pop_back();
   std::cout << "\nSecond pop_back   " << list;

   return EXIT_SUCCESS;
}
