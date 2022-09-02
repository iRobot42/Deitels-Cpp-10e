// Exercise 19.11: ex_19_11.cpp
// Copying a List in Reverse Order with a Stack and a List

#include "ForwardList.h"
#include "Stack.h"

int main() {

   ForwardList< char > list1;
   for ( char c{ '0' }; c <= '9'; ++c )
      list1.push_back( c );
   list1.print( "List #1" );

   Stack< char > stack;
   stack.print( "\nStack created" );
   while ( !list1.is_empty() )
      stack.push( list1.pop_front() );
   stack.print();

   ForwardList< char > list2;
   while ( !stack.is_empty() )
      list2.push_back( stack.pop() );
   list2.print( "\nList #2" );
   list1.print( "\nList #1" );
   stack.print();

   return EXIT_SUCCESS;
}
