// Exercise 20.5: ex_20_05.cpp
// Performance of Linear Search

#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;
using namespace chrono;

template< typename T >
T linearSearch( const vector< T >& ITEMS, const T& INDEX ) {
   for ( int i{}; i < ITEMS.size(); ++i )
      if ( i == INDEX )
         return ITEMS[ INDEX ];
   return -1;
}

int main( int argc, char** argv ) {

   const int N{ stoi( argv[ 1 ] ) };
   const int I{ stoi( argv[ 2 ] ) };

   default_random_engine generator{ random_device{}() };
   uniform_int_distribution< int > number( 0, 9999 );

   vector< int > vectorToSearch;
   for ( int i{}; i < N; ++i )
      vectorToSearch.push_back( number( generator ) );

   auto start{ high_resolution_clock::now() };
   int element{ linearSearch( vectorToSearch, I ) };
   auto stop{ high_resolution_clock::now() };

   cout << "Vector size: " << N << "\nSearch index: " << I << endl;
   if ( element != -1 )
      cout << "Element " << I << ": " << element;
   else cout << "Value not found";
   cout << "\nSearch time: "
      << duration_cast< milliseconds >( stop - start ).count() << " ms" << endl;

   return EXIT_SUCCESS;
}
