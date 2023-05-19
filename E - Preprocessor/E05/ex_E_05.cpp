// Exercise E.5: ex_E_05.cpp

#include <iostream>
using namespace std;

#define X 42
#define Y 69
#define SUM( x, y ) ( ( x ) + ( y ) )

int main() {

   cout << "The sum of " << X << " and " << Y << " is " << SUM( X, Y ) << endl;

   return EXIT_SUCCESS;
}
