// Exercise 19.24: Tree.h

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
   }

   void outputTree( const Node* PTR, const int SPACES ) const {

      if ( !PTR ) return;
      outputTree( PTR->right, SPACES + 5 );
      std::cout << std::string( SPACES, ' ' ) << PTR->data << '\n';
      outputTree( PTR->left, SPACES + 5 );
   }

public:

   void insert( const Type& DATA ) { insertHelper( &root, DATA ); }
   void output( int totalSpaces = 0 ) const { outputTree( root, totalSpaces ); }
};

#endif