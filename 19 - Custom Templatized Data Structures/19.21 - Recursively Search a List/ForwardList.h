// Exercise 19.21: List.h

#ifndef LIST_H
#define LIST_H

template< typename Type >
class ForwardList {

   struct Node {

      Type data{};
      Node* next{};

      explicit Node( const Type& DATA ) : data{ DATA } {};
   };

   Node* head{};
   Node* tail{};

   Type* searchHelper( Node* HEAD, const Type& DATA ) const {

      if ( !HEAD ) return nullptr;
      return HEAD->data == DATA
         ? &HEAD->data
         : searchHelper( HEAD->next, DATA );
   }

public:

   friend std::ostream& operator<<( std::ostream& out, const ForwardList& L ) {

      if ( L.head ) {
         Node* current{ L.head };
         do out << current->data << ' ';
         while ( current = current->next );
      } else out << "empty";
      return out;
   }

   ~ForwardList() {

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
         tail->next = temp;
         tail = temp;
      } else head = tail = temp;
   }

   Type* searchList( const Type& DATA ) const {
      return searchHelper( head, DATA );
   }
};

#endif