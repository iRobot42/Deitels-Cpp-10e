// Exercise 7.8: ex_07_08.cpp

#include <array>
#include <iostream>

using namespace std;

int main() {

   array< double, 17 > a;
   array< double, 41 > b;
   array< double, 200 > c;
   array< char, 10 > f;
   array< int, 4 > g;
   array< double, 999 > w;

   // a
   cout << f[ 5 ];

   // b
   b[ 3 ] = 3.3;

   // c
   g = { 7, 7, 7, 7 }; // or: array< int, 4 > g{ 7, 7, 7, 7 }; if not declared
   
   // d
   double total{ 0 };
   for ( const double& element : c )
      total += element;
   cout << total;

   // e
   for ( size_t i{ 0 }; i < a.size(); ++i )
      b[ i ] = a[ i ];

   // f
   double smallest{ w[ 0 ] };
   double largest{ w[ 0 ] };
   for ( const double& element : w ) {
      if ( element < smallest )
         smallest = element;
      if ( element > largest )
         largest = element;
   }
   cout << smallest << ' ' << largest;

   return 0;
}
