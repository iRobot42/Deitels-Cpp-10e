// Exercise 20.8: ex_20_08.cpp
// Comparing The Performance of Sorting Algorithms

#include <chrono>
#include <cmath>
#include <fstream>
#include <iostream>
#include <random>
#include <vector>

using namespace std;
using namespace chrono;

const size_t N{ 999 };

int main() {

   default_random_engine generator{ random_device{}() };
   uniform_int_distribution< int > number( 1, ::N );

   fstream file{ "array.dat", ios::binary | ios::in | ios::out };
   if ( !file ) {
      cerr << "File could not be opened" << endl;
      exit( EXIT_FAILURE );
   }

   file.seekp( ios::beg );
   for ( int i{}; i < ::N; ++i ) {
      int n{ number( generator ) };
      file.write( reinterpret_cast< char* >( &n ), sizeof( n ) );
   }

   vector< int > v;
   int n{};

   file.seekg( ios::beg );
   while ( file.read( reinterpret_cast< char* >( &n ), sizeof( n ) ) )
      v.push_back( n );

   auto start{ high_resolution_clock::now() }; // bubble

   for ( size_t i{ 1 }; i < ::N - 1; ++i ) {
      bool swapped{};
      for ( size_t j{}; j < ::N - i; ++j )
         if ( v[ j ] > v[ j + 1 ] ) {
            swap( v[ j ], v[ j + 1 ] );
            swapped = true;
         }
      if ( !swapped )
         break;
   }

   auto stop{ high_resolution_clock::now() };

   cout << "Bubble: "
      << duration_cast< microseconds >( stop - start ).count() << endl;

   v.clear();
   file.clear();

   file.seekg( ios::beg );
   while ( file.read( reinterpret_cast< char* >( &n ), sizeof( n ) ) )
      v.push_back( n );
   file.close();

   start = high_resolution_clock::now(); // bucket

   int max{ v[ 0 ] };
   for ( const auto& NUMBER : v )
      if ( NUMBER > max )
         max = NUMBER;

   int digits{ 1 };
   while ( max /= 10 )
      digits++;

   for ( int pass{}; pass < digits; ++pass ) {

      int b[ 10 ][ ::N ]{};
      int position[ 10 ]{};
      int index{};

      for ( const auto& NUMBER : v ) {
         int bucket{ NUMBER / static_cast< int >( pow( 10, pass ) ) % 10 };
         b[ bucket ][ position[ bucket ]++ ] = NUMBER;
      }

      for ( const auto& BUCKET : b )
         for ( const auto& NUMBER : BUCKET )
            if ( NUMBER )
               v[ index++ ] = NUMBER;
            else break;
   }

   stop = high_resolution_clock::now();

   cout << "Bucket: "
      << duration_cast< microseconds >( stop - start ).count() << endl;

   return EXIT_SUCCESS;
}
