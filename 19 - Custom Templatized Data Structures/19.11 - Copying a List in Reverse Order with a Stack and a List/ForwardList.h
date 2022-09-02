// Exercise 19.11: ForwardList.h

#ifndef FORWARDLIST_H
#define FORWARDLIST_H

#include <iostream>

template< typename Type >
class ForwardList {

   struct Node {
      Type data{ NULL };
      Node* next{};
      explicit Node( const Type& DATA ) : data{ DATA } {};
   };

   Node* head{};
   Node* tail{};

public:

   ForwardList() = default;

   ForwardList( const ForwardList& SRC ) {

      tail = head = SRC.head ? new Node( SRC.head->data ) : nullptr;
      if ( !head ) return;
      Node* current{ head };
      Node* cur_src{ SRC.head };
      while ( cur_src->next ) {
         cur_src = cur_src->next;
         tail = new Node( cur_src->data );
         current->next = tail;
         current = tail;
      }
   }

   ~ForwardList() {

      Node* temp{};
      while ( head ) {
         temp = head;
         head = head->next;
         delete temp;
      }
   }

   bool is_empty() const { return !head; }

   void push_front( const Type& DATA ) {

      Node* temp{ new Node( DATA ) };
      if ( head ) {
         temp->next = head;
         head = temp;
      } else head = tail = temp;
   }

   void push_back( const Type& DATA ) {

      Node* temp{ new Node( DATA ) };
      if ( head ) {
         tail->next = temp;
         tail = temp;
      } else head = tail = temp;
   }

   Type pop_front() {

      if ( !head ) return Type( NULL );
      Node* temp{ head };
      head = head != tail ? head->next : tail = nullptr;
      const Type DATA{ temp->data };
      delete temp;
      return DATA;
   }

   Type pop_back() {

      if ( !head ) return Type( NULL );
      Node* temp{ tail };
      if ( head != tail ) {
         Node* current{ head };
         while ( current->next != tail )
            current = current->next;
         tail = current;
         current->next = nullptr;
      } else head = tail = nullptr;
      const Type DATA{ temp->data };
      delete temp;
      return DATA;
   }

   void print( const std::string& INFO = "List" ) const {

      std::cout << INFO << ": ";
      if ( head ) {
         Node* current{ head };
         do std::cout << current->data << ' ';
         while ( current = current->next );
      } else std::cout << "empty";
      std::cout << std::endl;
   }
};

#endif