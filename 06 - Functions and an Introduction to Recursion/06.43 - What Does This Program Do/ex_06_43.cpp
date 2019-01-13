// Exercise 6.43: ex_06_43.cpp
// What does this program do?

#include <iostream>

using namespace std;

int mystery( int, int ); // function prototype

int main() {
   
   cout << "Enter two integers: ";
   
   int x{ 0 };
   int y{ 0 };
   
   cin >> x >> y;
   
   cout << "The result is " << mystery( x, y ) << endl;
}

// Parameter b must be a positive integer to prevent infinite recursion
int mystery( int a, int b ) {

   if ( 1 == b ) // base case
      return a;
   else // recursion step
      return a + mystery( a, b - 1 );
}

// My answer:

// This program calculates x * y and displays the result.
// Function "mystery" performs multiplication recursively.
