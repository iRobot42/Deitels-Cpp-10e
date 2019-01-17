// Exercise 7.16: ex_07_16.cpp

#include <array>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <random>

using namespace std;

int main() {

   default_random_engine generator{ static_cast< unsigned >( time( 0 ) ) };
   uniform_int_distribution< int > die{ 1, 6 };

   const int SUM{ 11 };
   array< int, SUM > frequency{};

   for ( int roll{ 1 }; roll <= 36'000'000; ++roll )
      ++frequency[ die( generator ) + die( generator ) - 2 ];

   cout << "Sum\tTotal\n-------------" << endl;

   for ( int i{ 0 }; i < SUM; ++i )
      cout << setw( 3 ) << i + 2 << setw( 10 ) << frequency[ i ] << endl;

   cout << "\nExpected ratio is 6.000, actual is "
      << setprecision( 3 ) << fixed << 36'000'000.0 / frequency[ 5 ] << endl;

   return 0;
}
