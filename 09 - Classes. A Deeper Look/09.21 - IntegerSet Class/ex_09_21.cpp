// Exercise 9.21: ex_09_21.cpp
// IntegerSet Class

#include <iostream>

#include "IntegerSet.h"

using namespace std;

int main() {

   array< int, SIZE > arr{ 42, 100, 1, 42 };
   arr[ 69 ] = 77;

   IntegerSet IS1; // empty
   IntegerSet IS2{ arr };

   cout << "Initial sets:\n"
      << IS1.toString() << endl
      << IS2.toString() << endl;

   IS2.deleteElement( 0 );
   IS1.insertElement( 0 );
   IS1.insertElement( 42 );
   IS1.insertElement( 99 );
   IS1.insertElement( 100 );

   cout << "\nModified sets:\n"
      << IS1.toString() << endl
      << IS2.toString() << endl;

   cout << "\nFirst set is "
      << ( IS1.isEqualTo( IS2 ) ? "" : "not " ) << "equal to second" << endl;

   cout << "\nUnion of two sets:\n"
      << IS1.unionOfSets( IS2 ).toString() << endl;

   cout << "\nIntersection of two sets:\n"
      << IS1.intersectionOfSets( IS2 ).toString() << endl;

   try {
      //IS1.insertElement( -1 );
      //IS1.deleteElement( 101 );
   }
   catch ( const char* ex ) {
      cerr << "\nException: " << ex << endl;
   }

   return 0;
}
