// Exercise 19.20: List.h

#ifndef LIST_H
#define LIST_H

template< typename Type >
class List {

   struct Node {

      Type data{};
      Node* prev{};
      Node* next{};

      explicit Node( const Type& DATA ) : data{ DATA } {};
   };

   Node* head{};
   Node* tail{};

   void printHelper( const Node* TAIL ) const {

      if ( !TAIL ) return;
      std::cout << TAIL->data << ' ';
      printHelper( TAIL->prev );
   }

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

   void printListBackward() const { printHelper( tail ); }
};

#endif