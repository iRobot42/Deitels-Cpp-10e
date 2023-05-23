// Exercise F.10: ex_F_10.cpp

#include <iostream>
using namespace std;

union Integer { char c; short s; int i; long l; };

inline void print( Integer u ) {
   cout << "Union: " << u.c << ' ' << u.s << ' ' << u.i << ' ' << u.l << endl;
}

int main() {

   Integer i{};

   i.c = '+', print( i );
   i.s = 42, print( i );
   i.i = 101, print( i );
   i.l = 99999, print( i );

   return EXIT_SUCCESS;
}
