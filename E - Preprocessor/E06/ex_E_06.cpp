// Exercise E.6: ex_E_06.cpp

#include <iostream>
using namespace std;

#define MINIMUM2( a, b ) min( ( a ), ( b ) )

int main() {

   cout << "Two numbers: ";
   int n1, n2;
   cin >> n1 >> n2;
   cout << "Smaller is " << MINIMUM2( n1, n2 ) << endl;

   return EXIT_SUCCESS;
}
