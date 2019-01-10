// Exercise 2.25: ex_02_25.cpp

#include <iostream>

using namespace std;

int main() {

   int n1, n2, n3;

   cout << "Three integer numbers: ";
   cin >> n1 >> n2 >> n3;

   if ( n3 % n1 == 0 ) cout << n1 << " is a factor of " << n3 << endl;
   if ( n3 % n2 == 0 ) cout << n2 << " is a factor of " << n3 << endl;

   return 0;
}
