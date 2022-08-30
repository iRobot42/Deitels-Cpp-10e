// Exercise 19.6: ex_19_06.cpp
// Concatenating Lists

#include "List.h"
using namespace std;

List concatenate( const List& L1, const List& L2 ) {
   List list;
   Node* temp{ L1.head };
   while ( temp ) {
      list.add( temp->data );
      temp = temp == L1.tail ? L2.head : temp->next;
   }
   return list;
}

int main() {

   List list1, list2;
   list1.print( "Lists #1 and #2 were declared" );

   srand( static_cast< unsigned >( time( NULL ) ) );
   for ( int i{}; i <= 3; ++i ) {
      list1.add( '0' + rand() % 10 );
      list2.add( 'a' + rand() % 26 );
   }
   list1.print( "\nList #1, after initialization" );
   list2.print( "\nList #2, after initialization" );

   List list3( concatenate( list1, list2 ) );
   list3.print( "\nList #3, concatenated" );
   list1.print( "\nList #1 was not concatenated" );

   return EXIT_SUCCESS;
}
