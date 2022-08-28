// Exercise 18.4: ex_18_04.cpp
// Array Class Template

#include "Array.h"
using namespace std;

template< typename T >
void outputArray( const Array< T >& A, const string& INFO ) {
   cout << boolalpha << INFO << "( " << A.getSize() << " ): " << A << endl;
}

int main() {

   Array< int > a( 3 ), b; // int, constructor
   cout << "Enter " << a.getSize() << " integer numbers: "; // getSize()
   cin >> a; // operator>>
   outputArray( a, "\nInitial integer Array a" ); // operator<<
   outputArray( b, "Default integer Array b" );

   const Array< int > C( b = a ); // copy constructor, operator=
   outputArray( b, "\nModified Array b" );
   outputArray( C, "Copy of b, constant integer Array C" );
   cout << "First element in C is " << C[ 0 ]; // const operator[]

   cout << "\n\nArray C is " << ( C == a ? "" : "not " ) // operator==
      << "equal to Array a\n";
   b[ 2 ] = 911; // non-const operator[]
   cout << "After changes in b, C is "
      << ( C != b ? "not " : "" ) << "equal to b\n"; // operator!=

   Array< bool > d( 4 ); // bool
   d[ 1 ] = d[ 2 ] = true;
   outputArray( d, "\nbool    d" );

   Array< float > e( 2 ); // float
   e[ 0 ] = 3.14f;
   e[ 1 ] = 2.718f;
   outputArray( e, "float   e" );

   Array< char > f( 8 ); // char
   f[ 0 ] = '#';
   f[ 1 ] = '1';
   outputArray( f, "char    f" );

   Array< string > g( 1 ); // string
   g[ 0 ] = "iR080T";
   outputArray( g, "string  g" );

   cout << "\nEXCEPTIONS:\n";
   for ( int ex{ 1 }; ex <= 2; ++ex ) {
      try {
         switch ( ex ) {
         case 1: cout << "Invalid size: "; { Array< int > h( -1 ); }
         case 2: cout << "Invalid index: "; g[ 1 ] = true;
         }
      }
      catch ( const exception& EX ) { cerr << EX.what() << endl; }
   }
   cout << endl;

   // 7 destructors

   return EXIT_SUCCESS;
}
