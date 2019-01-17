// Exercise 7.11: ex_07_11.cpp

#include <array>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {

   array< double, 10 > values{ // a
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5 };

   for ( size_t i{ 1 }; i < values.size(); i += 2 ) // b
      ++values[ i ];

   for ( size_t i{ 0 }; i < 5; ++i ) // c
      cin >> values[ i ];

   for ( size_t i{ 0 }; i < values.size(); ++i ) { // d
      cout << fixed << setprecision( 2 ) << values[ i ] << ' ';
      if ( 4 == i )
         cout << endl;
   }

   return 0;
}
