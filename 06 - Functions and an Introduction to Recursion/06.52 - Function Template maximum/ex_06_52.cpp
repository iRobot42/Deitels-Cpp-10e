// Exercise 6.52: ex_06_52.cpp

#include <iostream>

using namespace std;

template < typename T >
T maximum( T n1, T n2 ) { return n1 > n2 ? n1 : n2; }

int main() {

   cout << maximum( 1, -1 ) << endl // int
      << maximum( '@', 'a' ) << endl // char
      << maximum( 4.2, 4.02 ) << endl; // double

   return 0;
}
