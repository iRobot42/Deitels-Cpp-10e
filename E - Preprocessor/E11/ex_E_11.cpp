// Exercise E.11: ex_E_11.cpp

#include <iomanip>
#include <iostream>
using namespace std;

const double PI{ 3.14159 };

inline double SV( int r ) { return 4.0 * ::PI * r * r * r / 3; }
inline int SUM( int x, int y ) { return x + y; }
inline int MINIMUM2( int a, int b ) { return min( a, b ); }
inline int MINIMUM3( int a, int b, int c ) {
   return MINIMUM2( MINIMUM2( a, b ), c );
}
inline void PRINT( const string& s ) { cout << s << endl; }
inline void PRINTARRAY( const int a[], int n ) {
   for ( int i{}; i < n; ++i )
      cout << a[ i ] << ' ';
   cout << endl;
}
inline void SUMARRAY( const int a[], int n ) {
   int s{};
   for ( int i{}; i < n; ++i )
      s += a[ i ];
   cout << s << endl;
}

int main() {

   // E.4
   cout << "radius\t volume\n" << string( 15, '-' ) << endl;
   cout << fixed << setprecision( 2 );
   for ( int i{ 1 }; i <= 10; ++i )
      cout << setw( 6 ) << i << '\t' << setw( 7 ) << SV( i ) << endl;

   // E.5
   const int X{ 42 }, Y{ 69 };
   cout << "The sum of " << X << " and " << Y << " is " << SUM( X, Y ) << endl;

   // E.6
   cout << "Two numbers: ";
   int n1, n2;
   cin >> n1 >> n2;
   cout << "Smaller is " << MINIMUM2( n1, n2 ) << endl;

   // E.7
   cout << "Three numbers: ";
   int n3;
   cin >> n1 >> n2 >> n3;
   cout << "Smaller is " << MINIMUM3( n1, n2, n3 ) << endl;

   // E.8
   const string test{ "Lorem ipsum dolor sit amet" };
   PRINT( test );

   // E.9
   const int A[]{ 42, -1, 1024, 0, 365 };
   PRINTARRAY( A, sizeof( A ) / sizeof( *A ) );

   // E.10
   const int N{ sizeof( A ) / sizeof( *A ) };
   SUMARRAY( A, N );

   return EXIT_SUCCESS;
}
