// Exercise 19.16: Tree.h

#ifndef TREE_H
#define TREE_H

#include <iostream>

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
      else std::cout << "\nDuplicate: " << DATA << '\n';
   }

   void preorderHelper( Node* ptr ) const {

      if ( !ptr ) return;
      std::cout << ptr->data << ' ';
      preorderHelper( ptr->left );
      preorderHelper( ptr->right );
   }

   void inorderHelper( Node* ptr ) const {

      if ( !ptr ) return;
      inorderHelper( ptr->left );
      std::cout << ptr->data << ' ';
      inorderHelper( ptr->right );
   }

   void postorderHelper( Node* ptr ) const {

      if ( !ptr ) return;
      postorderHelper( ptr->left );
      postorderHelper( ptr->right );
      std::cout << ptr->data << ' ';
   }

public:

   void insert( const Type& DATA ) { insertHelper( &root, DATA ); }
   void preorderTraversal() const  { preorderHelper( root ); }
   void inorderTraversal() const   { inorderHelper( root ); }
   void postorderTraversal() const { postorderHelper( root ); }
};

#endif