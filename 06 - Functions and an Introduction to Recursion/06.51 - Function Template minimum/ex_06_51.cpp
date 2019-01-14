// Exercise 6.51: ex_06_51.cpp

#include <iostream>

using namespace std;

template < typename T >
T minimum( T n1, T n2 ) { return n1 < n2 ? n1 : n2; }

int main() {

   cout << minimum( 1, -1 ) << endl // int
      << minimum( '@', 'a' ) << endl // char
      << minimum( 4.2, 4.02 ) << endl; // double

   return 0;
}
