// Exercise 15.22: ex_15_22.cpp
// Palindromes

#include <iostream>
#include <vector>

using namespace std;

template< typename T >
bool palindrome( const vector< T >& VECTOR ) {

   if ( VECTOR.empty() ) return false;
   if ( VECTOR.size() == 1 ) return true;

   auto front{ VECTOR.cbegin() };
   auto back{ VECTOR.crbegin() };

   const size_t N{ VECTOR.size() / 2 - 1 };
   for ( size_t i{}; i <= N; ++i )
      if ( *front++ != *back++ )
         return false;

   return true;
}

int main() {

   vector< int > v1{ 1, 2, 3, 2, 1 };
   vector< int > v2{ 1, 2, 3, 4 };

   cout << boolalpha
      << palindrome( v1 ) << '\n'
      << palindrome( v2 ) << endl;

   return EXIT_SUCCESS;
}
