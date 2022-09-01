// Exercise 19.9: ex_19_09.cpp
// Copying a List in Reverse Order with Singly Linked Lists

#include "ForwardList.h"

template< typename Type >
ForwardList< Type > reverse_copy( const ForwardList< Type >& LIST ) {
   ForwardList< Type > src{ LIST }, dest;
   while ( !src.is_empty() )
      dest.push_front( src.pop_front() );
   return dest;
}

int main() {

   ForwardList< char > list1;
   for ( char c{ '0' }; c <= '9'; ++c )
      list1.push_back( c );
   list1.print( "List #1 was populated" );

   ForwardList< char > list2{ reverse_copy( list1 ) };
   list2.print( "\nList #2, reverse copy" );
   list1.print( "\nList #1, not modified" );

   return EXIT_SUCCESS;
}
