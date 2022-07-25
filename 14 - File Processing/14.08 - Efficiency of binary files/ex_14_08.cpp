// Exercise 14.8: ex_14_08.cpp
// Efficiency of binary files

#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

void txt( int, int );
void bin( int, int );

long long runtime( void( & )( int, int ), int, int );

int main() {

   const int NUMBER{ -42 };
   const int VALUES{ 1'000'000 };

   cout << "Text: " << runtime( txt, NUMBER, VALUES ) << " ms" << endl;
   cout << "Binary: " << runtime( bin, NUMBER, VALUES ) << " ms" << endl;

   return 0;
}

void txt( int number, int values ) {

   vector< int > numbers;

   ofstream ofTxt( "txt.dat", ios::out );
   if ( !ofTxt ) exit( EXIT_FAILURE );

   ofTxt.seekp( 0 );
   while ( values-- )
      ofTxt << number++ << ' ';

   ofTxt.close();

   ifstream ifTxt( "txt.dat", ios::in );
   if ( !ifTxt ) exit( EXIT_FAILURE );

   ifTxt.seekg( 0 );
   while ( ifTxt >> number )
      numbers.push_back( number );

   ifTxt.close();
}

void bin( int number, int values ) {

   vector< int > numbers;

   ofstream ofBin( "bin.dat", ios::binary | ios::out );
   if ( !ofBin ) exit( EXIT_FAILURE );

   ofBin.seekp( 0 );
   for ( int i{ number }; i < number + values; ++i )
      ofBin.write( reinterpret_cast< const char* >( &i ), sizeof( i ) );

   ofBin.close();

   ifstream ifBin( "bin.dat", ios::binary | ios::in );
   if ( !ifBin ) exit( EXIT_FAILURE );

   ifBin.seekg( 0 );
   while ( ifBin.read( reinterpret_cast< char* >( &number ), sizeof( number ) ) )
      numbers.push_back( number );

   ifBin.close();
}

long long runtime( void( &f )( int, int ), int n, int v ) {

   auto start = high_resolution_clock::now();
   f( n, v );
   auto stop = high_resolution_clock::now();

   return duration_cast< milliseconds >( stop - start ).count();
}
