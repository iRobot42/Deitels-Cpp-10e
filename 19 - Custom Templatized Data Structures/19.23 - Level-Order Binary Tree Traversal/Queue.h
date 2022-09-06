// Exercise 19.23: Queue.h

#ifndef QUEUE_H
#define QUEUE_H

template< typename Type >
class Queue {

   struct Node {

      Type data{};
      Node* next{};

      explicit Node( const Type& DATA ) : data{ DATA } {};
   };

   Node* head{};
   Node* tail{};

public:

   ~Queue() {

      Node* temp{};
      while ( head ) {
         temp = head;
         head = head->next;
         delete temp;
      }
   }

   bool empty() const { return !head; }

   void push( const Type& DATA ) {

      Node* temp{ new Node( DATA ) };
      if ( head ) {
         tail->next = temp;
         tail = temp;
      } else head = tail = temp;
   }

   Type pop() {

      if ( !head ) throw;
      Node* temp{ head };
      head = head != tail ? head->next : tail = nullptr;
      const Type DATA{ temp->data };
      delete temp;
      return DATA;
   }
};

#endif