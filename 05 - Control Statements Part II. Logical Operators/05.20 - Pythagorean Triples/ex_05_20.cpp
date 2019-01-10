// Exercise 5.20: ex_05_20.cpp

#include <iostream>

using namespace std;

int main() {

   for ( int hypotenuse{ 1 }; hypotenuse <= 500; ++hypotenuse )
      for ( int side1{ 1 }; side1 < hypotenuse; ++side1 )
         for ( int side2{ 1 }; side2 <= side1; ++side2 )
            if ( hypotenuse * hypotenuse == side1 * side1 + side2 * side2 )
               cout << hypotenuse << '\t' << side1 << '\t' << side2 << endl;

   return 0;
}
