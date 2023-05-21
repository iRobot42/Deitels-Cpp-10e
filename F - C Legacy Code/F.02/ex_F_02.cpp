// Exercise F.2: ex_F_02.cpp

#include <cstdarg>
#include <iostream>
using namespace std;

long long product( int, ... );

int main() {

   int a{ 42 }, b{ -1 }, c{ -10 }, d{ INT_MAX }, e{};

   cout << product( 2, a, b ) << endl;
   cout << product( 3, c, b, a ) << endl;
   cout << product( 4, a, b, c, d ) << endl;
   cout << product( 5, a, b, c, d, e ) << endl;

   return EXIT_SUCCESS;
}

long long product( int c, ... ) {

   long long p{ 1 };
   va_list list;

   va_start( list, c );
   while ( c-- ) p *= va_arg( list, int );
   va_end( list );

   return p;
}
