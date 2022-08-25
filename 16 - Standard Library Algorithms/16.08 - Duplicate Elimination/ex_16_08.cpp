// Exercise 16.8: ex_16_08.cpp
// Duplicate Elimination

#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>

using namespace std;

int main() {

   const size_t SIZE{ 20 };
   array< int, SIZE > ints;
   ostream_iterator< int > out{ cout, " " };

   cout << SIZE << " integers: ";
   for ( auto& i : ints )
      cin >> i;

   sort( ints.begin(), ints.end() );

   auto end{ unique( ints.begin(), ints.end() ) };

   cout << "Unique values are ";
   copy( ints.begin(), end, out );
   cout << endl;

   return EXIT_SUCCESS;
}
