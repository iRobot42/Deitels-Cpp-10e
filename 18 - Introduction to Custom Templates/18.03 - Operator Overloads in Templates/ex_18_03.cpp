// Exercise 18.3: ex_18_03.cpp
// Operator Overloads in Templates

#include <iostream>
using namespace std;

template< typename T >
bool isEqualTo( const T& A, const T& B ) {
   return A == B;
}

template< typename T >
class Type {
public:
   explicit Type( const T& M = NULL ) : member{ M } {};
   bool operator==( const Type& RIGHT ) const {
      return member == RIGHT.member;
   }
private:
   T member;
};

int main() {

   const Type< int > T1, T2{ 1 };

   cout << isEqualTo( true, false ) << isEqualTo( 42, 42 )
      << isEqualTo( 3.14, 3.14159 ) << isEqualTo( '#', '#' )
      << isEqualTo( T1, T2 ) << endl; // 01010

   return EXIT_SUCCESS;
}
