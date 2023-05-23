// Exercise F.11: ex_F_11.cpp

#include <iostream>
using namespace std;

union FloatingPoint {
   float float1;
   double double1;
   long double longDouble;
};

inline void print( FloatingPoint u ) {
   cout << "Union: "
      << u.float1 << ' '
      << u.double1 << ' '
      << u.longDouble << endl;
}

int main() {

   FloatingPoint f{};

   f.float1 = -.0f, print( f );
   f.double1 = 42.69, print( f );
   f.longDouble = 1e99, print( f );

   return EXIT_SUCCESS;
}
