// Exercise 6.48: ex_06_48.cpp

#include <iostream>

using namespace std;

inline double circleArea( double radius ) {
   return 3.14159 * radius * radius;
}

int main() {

   double r;

   do {
      cout << "Circle radius: ";
      cin >> r;
   } while ( r <= 0 );

   cout << "Area is " << circleArea( r ) << endl;

   return 0;
}
