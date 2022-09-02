// Exercise 19.11: Stack.h

#ifndef STACK_H
#define STACK_H

template< typename Type >
struct Stack : private ForwardList< Type > {

   void push( const Type& DATA ) {
      this->push_front( DATA );
   }
   Type pop() {
      return this->pop_front();
   }
   bool is_empty() const {
      return this->ForwardList< Type >::is_empty();
   }
   void print( const std::string& INFO = "Stack" ) const {
      ForwardList< Type >::print( INFO );
   }
};

#endif