// Exercise 19.26: ForwardList.h

#ifndef FORWARDLIST_H
#define FORWARDLIST_H

template< typename Type >
class ForwardList {

   struct Node {

      Type data{};
      Node* next{};

      explicit Node( const Type& DATA ) : data{ DATA } {};
   };

   Node* head{};

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

   bool is_empty() const { return !head; }

   void push_front( const Type& DATA ) {

      Node* temp{ new Node( DATA ) };
      if ( head ) {
         temp->next = head;
         head = temp;
      } else head = temp;
   }

   void push_back( const Type& DATA ) {

      Node* temp{ new Node( DATA ) };
      if ( head ) {
         Node* current{ head };
         while ( current->next )
            current = current->next;
         current->next = temp;
      } else head = temp;
   }

   Type pop_front() {

      if ( !head ) throw;
      Node* temp{ head };
      head = head->next;
      const Type DATA{ temp->data };
      delete temp;
      return DATA;
   }

   Type pop_back() {

      if ( !head ) throw;
      Node* temp{ head };
      if ( temp->next ) {
         Node* current{ head };
         while ( current->next->next )
            current = current->next;
         temp = current->next;
         current->next = nullptr;
      } else head = nullptr;
      const Type DATA{ temp->data };
      delete temp;
      return DATA;
   }
};

#endif