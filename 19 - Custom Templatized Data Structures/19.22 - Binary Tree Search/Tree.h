// Exercise 19.22: Tree.h

#ifndef TREE_H
#define TREE_H

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

   void inorderHelper( Node* ptr ) const {

      if ( !ptr ) return;
      inorderHelper( ptr->left );
      std::cout << ptr->data << ' ';
      inorderHelper( ptr->right );
   }

   Node* binaryTreeSearch( Node* node, const Type& KEY ) const {

      if ( !node ) return nullptr;
      if ( node->data == KEY ) return node;
      else return node->data > KEY
         ? binaryTreeSearch( node->left, KEY )
         : binaryTreeSearch( node->right, KEY );
   }

public:

   void insert( const Type& DATA ) { insertHelper( &root, DATA ); }
   void inorderTraversal() const   { inorderHelper( root ); }

   Type* search( const Type& KEY ) {

      Node* result{ binaryTreeSearch( root, KEY ) };
      return result ? &result->data : nullptr;
   }
};

#endif