// Exercise E.7: ex_E_07.cpp

#include <iostream>
using namespace std;

#define MINIMUM2( a, b ) min( ( a ), ( b ) )
#define MINIMUM3( a, b, c ) MINIMUM2( MINIMUM2( ( a ), ( b ) ), ( c ) )

int main() {

   cout << "Three numbers: ";
   int n1, n2, n3;
   cin >> n1 >> n2 >> n3;
   cout << "Smaller is " << MINIMUM3( n1, n2, n3 ) << endl;

   return EXIT_SUCCESS;
}
