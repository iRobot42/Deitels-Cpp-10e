// Exercise 16.10: ex_16_10.cpp
// Reading Data from a File

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {

   ifstream file{ "integers.txt" };
   if ( !file ) {
      cerr << "File could not be opened" << endl;
      exit( EXIT_FAILURE );
   }

   vector< int > ints;

   copy( istream_iterator< int >{ file },
         istream_iterator< int >{},
         back_inserter( ints ) );

   file.close();

   for ( const auto& i : ints )
      cout << i << ' ';

   return EXIT_SUCCESS;
}
