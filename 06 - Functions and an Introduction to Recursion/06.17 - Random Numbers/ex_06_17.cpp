// Exercise 6.17: ex_06_17.cpp

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main() {

   srand( time( 0 ) );

   cout << 0 + rand() % 5 * 3 << endl; // a
   cout << 3 + rand() % 6 * 2 << endl; // b
   cout << 6 + rand() % 4 * 4 << endl; // c

   return 0;
}
