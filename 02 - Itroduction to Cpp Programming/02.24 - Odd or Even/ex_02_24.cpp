// Exercise 2.24: ex_02_24.cpp

#include <iostream>

using namespace std;

int main() {

   int n1, n2;

   cout << "Two integer numbers: ";
   cin >> n1 >> n2;
   
   if ( n1 % 2 ) cout << n1 << " is odd.\n";
   if ( n2 % 2 ) cout << n2 << " is odd.\n";
   if ( ( n1 + n2 ) % 2 ) cout << "Sum (" << n1 + n2 << ") is odd." << endl;

   return 0;
}
