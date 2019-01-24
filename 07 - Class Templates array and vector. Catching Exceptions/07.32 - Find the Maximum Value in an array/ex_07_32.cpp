// Exercise 7.32: ex_07_32.cpp

#include <array>
#include <iostream>

using namespace std;

const size_t SIZE{ 5 };

int recursiveMaximum( const array< int, SIZE >& A, size_t s, size_t e ) {
   
   static int max{ A[ s ] };

   if ( A[ s ] > max )
      max = A[ s ];

   return s == e ? max : recursiveMaximum( A, s + 1, e );
}

int main() {

   array< int, ::SIZE > test{ -1, 2, -2, 0, 1 };

   cout << "Largest number is "
      << recursiveMaximum( test, 0, ::SIZE - 1 ) << endl;

   return 0;
}
