// Exercise 7.3: ex_07_03.cpp

#include <array>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {

   const size_t arraySize{ 8 }; // a
   array< double, arraySize > fractions{ // b
      1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 };

   fractions[ 2 ]; // c
   fractions[ 3 ]; // d

   fractions[ 7 ] = 1.667; // e
   fractions[ 5 ] = 3.333; // f
   
   cout << fixed << setprecision( 1 ) // g
      << fractions[ 5 ] << ' ' << fractions[ 7 ];
   // output: 3.3 1.7
   
   for ( size_t j{ 0 }; j < fractions.size(); ++j ) // h
      cout << fractions[ j ] << ' ';
   // output: 1 1 1 1 1 3.333 1 1.667 (if no stream manipulators used)

   for ( const double& element : fractions ) // i
      cout << element << '-';

   return 0;
}
