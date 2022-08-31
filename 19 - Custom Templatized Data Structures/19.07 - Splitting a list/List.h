// Exercise 19.7: List.h

#ifndef LIST_H
#define LIST_H

#include <iostream>

struct Node {
   char data{};
   Node* next{};
};

struct List {

   Node* head{}; // not safe,
   Node* tail{}; // but enough

   void add( const char C ) {
      Node* temp = new Node;
      temp->data = C;
      if ( head ) {
         tail->next = temp;
         tail = tail->next;
      } else head = tail = temp;
   }

   void print( const std::string& INFO ) const {
      std::cout << INFO << ": ";
      if ( head ) {
         Node* current{ head };
         do std::cout << current->data << ' ';
         while ( current = current->next );
      } else std::cout << "empty";
   }
};

#endif
