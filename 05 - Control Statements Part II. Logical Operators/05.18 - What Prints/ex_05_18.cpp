// Exercise 5.18: ex_05_18.cpp

#include <iostream>

using namespace std;

int main() {

   int a{ 4 };
   int b{ 3 };
   int c{ 2 };
   int d{ 1 };

   // a
   cout << ( a == 1 ) << endl; // 0
   // b
   cout << ( b == 3 ) << endl; // 1
   // c
   cout << ( d >= 1 && c < 4 ) << endl; // 1
   // d
   cout << ( d <= 4 && b < d ) << endl; // 0
   // e
   cout << ( b >= d || c == a ) << endl; // 1
   // f
   cout << ( c + d < b || b >= a ) << endl; // 0
   // g
   cout << ( !d ) << endl; // 0
   // h
   cout << ( !( a - b ) ) << endl; // 0
   // i
   cout << ( !( c < d ) ) << endl; // 1

   return 0;
}
