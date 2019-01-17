// Exercise 7.9: ex_07_09.cpp

#include <array>
#include <iostream>

using namespace std;

int main() {

   // a
   array< array< int, 3 >, 2 > t;
   // or: array< array< int, COLUMNS >, ROWS > t; if initialized

   // b: 2
   // c: 3
   // d: 6
   // e: t[1][0], t[1][1], t[1][2]
   // f: t[0][1], t[1][1]

   // g
   t[ 0 ][ 1 ] = 0;

   // h
   t = {};
   t = { 0 };
   t = { 0, 0, 0, 0, 0, 0 };
   t[0][0] = t[0][1] = t[0][2] = t[1][0] = t[1][1] = t[1][2] = 0;

   // i
   for ( size_t row{ 0 }; row < t.size(); ++row )
      for ( size_t col{ 0 }; col < t[ row ].size(); ++col )
         t[ row ][ col ] = 0;

   // j
   for ( auto& row : t )
      for ( auto& element : row )
         element = 0;

   // k
   for ( auto& row : t )
      for ( auto& element : row )
         cin >> element;
   
   // l
   int smallest{ t[ 0 ][ 0 ] };
   for ( const auto& row : t )
      for ( const auto& element : row )
         if ( element < smallest )
            smallest = element;
   cout << smallest;

   // m
   for ( size_t col{ 0 }; col < t[ 0 ].size(); ++col )
      cout << t[ 0 ][ col ] << ' ';

   // n
   int total{ 0 };
   for ( size_t row{ 0 }; row < t.size(); ++row )
      total += t[ row ][ 2 ];

   // o
   cout << '\t';
   for ( size_t hCol{ 0 }; hCol < t[ 0 ].size(); ++hCol )
      cout << '[' << hCol << "]\t";
   cout << "\n\n";
   // or: cout << "\t[0]\t[1]\t[2]\n\n";
   for ( size_t row{ 0 }; row < t.size(); ++row ) {
      cout << '[' << row << "]\t";
      for ( size_t col{ 0 }; col < t[ row ].size(); ++col )
         cout << t[ row ][ col ] << '\t';
      cout << endl;
   }

   return 0;
}
