// Exercise 19.23: Tree.h

#ifndef TREE_H
#define TREE_H

#include "Queue.h"

template< typename Type >
class Tree {

   struct Node {

      Type data{};
      Node* left{};
      Node* right{};

      explicit Node( const Type& DATA ) : data{ DATA } {}
   };

   Node* root{};

   void insertHelper( Node** ptr, const Type& DATA ) {

      if ( !*ptr )
         *ptr = new Node( DATA );
      else if ( DATA < ( *ptr )->data )
         insertHelper( &( ( *ptr )->left ), DATA );
      else if ( DATA > ( *ptr )->data )
         insertHelper( &( ( *ptr )->right ), DATA );
      else std::cout << "\nDuplicate: " << DATA;
   }

public:

   void insert( const Type& DATA ) { insertHelper( &root, DATA ); }

   void levelOrder() const {

      if ( !root ) return;
      Queue< Node* > queue;
      Node* temp;
      queue.push( root );
      while ( !queue.empty() ) {
         temp = queue.pop();
         std::cout << temp->data << ' ';
         if ( temp->left ) queue.push( temp->left );
         if ( temp->right ) queue.push( temp->right );
      }
   }
};

#endif