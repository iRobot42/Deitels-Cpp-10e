// Exercise 6.37: ex_06_37.cpp

#include <iostream>

using namespace std;

int fibonacci( int );

int main() {

   const int MAX{ 47 }; // 4-byte signed int

   cout << "Number\tFibonacci\n" << endl;

   for ( int i{ 1 }; i <= MAX; ++i )
      cout << i << '\t' << fibonacci( i ) << endl;

   return 0;
}

int fibonacci( int n ) {

   int pr1{ 0 }; // 1st preceding term
   int pr2{ 1 }; // 2nd preceding term
   int fib{ 1 };

   for ( int i{ 3 }; i <= n; ++i ) {
      fib = pr1 + pr2;
      pr1 = pr2;
      pr2 = fib;
   }

   return n == 1 ? 0 : fib;
}
