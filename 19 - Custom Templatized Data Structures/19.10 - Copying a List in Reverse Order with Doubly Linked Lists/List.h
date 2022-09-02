// Exercise 19.10: List.h

#ifndef LIST_H
#define LIST_H

#include <iostream>

template< typename Type >
class List {

   struct Node {

      Node* prev{};
      Type data{ NULL };
      Node* next{};

      explicit Node( const Type& DATA ) : data{ DATA } {};
   };

   Node* head{};
   Node* tail{};

public:

   friend std::ostream& operator<<( std::ostream& out, const List& L ) {

      if ( L.head ) {
         Node* current{ L.head };
         do out << current->data << ' ';
         while ( current = current->next );
      } else out << "empty";
      return out;
   }

   ~List() {

      Node* temp{};
      while ( head ) {
         temp = head;
         head = head->next;
         delete temp;
      }
   }

   void push_back( const Type& DATA ) {

      Node* temp{ new Node( DATA ) };
      if ( head ) {
         temp->prev = tail;
         tail->next = temp;
         tail = temp;
      } else head = tail = temp;
   }

   void copyFromBack( List& reversed ) {

      if ( !head ) return;
      Node* current{ tail };
      do reversed.push_back( current->data );
      while ( current = current->prev );
   }
};

#endif