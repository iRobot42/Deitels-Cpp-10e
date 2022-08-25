// Exercise 16.9: ex_16_09.cpp
// Duplicate Elimination

#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main() {

   const size_t SIZE{ 20 };
   array< int, SIZE > ints;
   vector< int > result;
   ostream_iterator< int > out{ cout, " " };

   cout << SIZE << " integers: ";
   for ( auto& i : ints )
      cin >> i;

   sort( ints.begin(), ints.end() );
   unique_copy( ints.cbegin(), ints.cend(), back_inserter( result ) );

   cout << "Unique values are ";
   copy( result.cbegin(), result.cend(), out );
   cout << endl;

   return EXIT_SUCCESS;
}
