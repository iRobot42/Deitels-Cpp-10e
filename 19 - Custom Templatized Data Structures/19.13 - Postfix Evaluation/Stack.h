// Exercise 19.13: Stack.h

#ifndef STACK_H
#define STACK_H

template< typename Type >
class Stack {

   struct Node {
      Type data{ NULL };
      Node* next{};
      explicit Node( const Type& DATA ) : data{ DATA } {};
   };

   Node* head{};

public:

   ~Stack() {

      Node* temp{};
      while ( head ) {
         temp = head;
         head = head->next;
         delete temp;
      }
   }

   void push( const Type& DATA ) {

      Node* temp{ new Node( DATA ) };
      if ( head ) {
         temp->next = head;
         head = temp;
      }
      else head = temp;
   }

   Type pop() {

      if ( !head ) return Type( NULL );
      Node* temp{ head };
      head = head->next;
      const Type DATA{ temp->data };
      delete temp;
      return DATA;
   }

   //Type top() { return head->data; }
   //bool empty() const { return !head; }
};

#endif