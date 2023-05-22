// Exercise F.4: ex_F_04.cpp

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main( int argc, char** argv ) {

   vector< int > v{ 42, -1, 1024, 0, 365 };

   cout << "Command argument: " << argv[ 1 ] << "\nVector: ";
   for ( const int i : v ) cout << i << ' ';

   if      ( argv[ 1 ] == "-a"s ) sort( v.begin(), v.end() );
   else if ( argv[ 1 ] == "-d"s ) sort( v.rbegin(), v.rend() );

   cout << "\nResult: ";
   for ( const int i : v ) cout << i << ' ';
   cout << endl;

   return EXIT_SUCCESS;
}
