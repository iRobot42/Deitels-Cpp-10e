// Exercise 19.25: ForwardList.h

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
   Node* tail{};

public:

   friend std::ostream& operator<<( std::ostream& out, const ForwardList& L ) {

      if ( L.head ) {
         Node* current{ L.head };
         do out << current->data << ' ';
         while ( current = current->next );
      } else out << "empty";
      return out;
   }

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

   void insert( int pos, const Type& DATA ) {

      Node* temp{ new Node( DATA ) };
      if ( head ) {
         if ( !pos ) {
            temp->next = head;
            head = temp;
            return;
         }
         Node* current{ head };
         while ( --pos )
            current = current->next;
         temp->next = current->next;
         current->next = temp;
      } else head = tail = temp;
   }

   Type pop_front() {

      if ( !head ) throw;
      Node* temp{ head };
      head = head != tail ? head->next : tail = nullptr;
      const Type DATA{ temp->data };
      delete temp;
      return DATA;
   }

   Type pop_back() {

      if ( !head ) throw;
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

   void erase( int pos ) {

      if ( !head ) return;
      Node* current{ head };
      if ( !pos ) {
         if ( head->next )
            head = head->next;
         delete current;
         return;
      }
      while ( --pos )
         current = current->next;
      if ( current->next == tail )
         tail = current;
      Node* temp{ current->next };
      current->next = temp->next;
      delete temp;
   }
};

#endif