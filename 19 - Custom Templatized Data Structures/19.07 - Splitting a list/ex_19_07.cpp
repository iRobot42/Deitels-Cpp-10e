// Exercise 19.7: ex_19_07.cpp
// Splitting a list

#include "List.h"
using namespace std;

List split( List& l1, int pos ) {
   Node* temp{ l1.head };
   while ( --pos && temp->next ) temp = temp->next;
   List* l2 = new List{ temp->next };
   temp->next = nullptr;
   l1.tail = temp;
   return *l2;
}

int main() {

   srand( static_cast< unsigned >( time( NULL ) ) );

   List list1;
   for ( int i{}; i < 7; ++i )
      list1.add( 'A' + rand() % 26 );
   list1.print( "List #1 initialized" );

   List list2{ split( list1, 4 ) };
   list1.print( "\nList #1 after split" );
   list2.print( "\nList #2 after split" );

   return EXIT_SUCCESS;
}
