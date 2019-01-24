// Exercise 7.31: ex_07_31.cpp

#include <iostream>
#include <string>

using namespace std;

void stringReverse( const string& S, size_t i ) {
   if ( i < S.size() - 1 )
      stringReverse( S, i + 1 );
   cout << S[ i ];
}

int main() {

   string test{ "Hello, world!" };

   stringReverse( test, 0 );

   cout << endl;
   return 0;
}
