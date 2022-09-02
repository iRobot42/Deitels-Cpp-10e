// Exercise 19.10: ex_19_10.cpp
// Copying a List in Reverse Order with Doubly Linked Lists

#include "List.h"

int main() {

   List< int > list1, list2;
   for ( int i{}; i <= 9; ++i )
      list1.push_back( i );
   std::cout <<   "#1  initialized   " << list1
             << "\n#2  declared      " << list2;

   list1.copyFromBack( list2 );
   std::cout << "\n#2  reverse copy  " << list2
             << "\n#1  intact        " << list1;

   return EXIT_SUCCESS;
}
