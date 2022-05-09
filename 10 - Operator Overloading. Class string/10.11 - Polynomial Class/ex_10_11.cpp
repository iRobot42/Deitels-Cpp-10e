// Exercise 10.11: ex_10_11.cpp
// Polynomial Class

#include <iostream>
#include "Polynomial.h"

using namespace std;

int main() {

   Polynomial p1;
   Polynomial p2{ 4 };

   cout << "Enter polynomials (" << ( p1.getSize() + p2.getSize() ) * 2
      << " numbers): ";
   cin >> p1 >> p2;

   cout << "\np1 is " << p1 << "\np2 is " << p2
      << "\n\nSize of p2 is " << p2.getSize() << endl;

   Polynomial p3{ p2 };

   cout << "\np3 is " << p3 << endl;

   p3 = p1;
   cout << "After p3 = p1, p3 is " << p3 << endl
      << "\np1 + p2 = " << ( p1 + p2 )
      << "\np1 - p2 = " << ( p1 - p2 )
      << "\np1 * p2 = " << ( p1 * p2 ) << "\n\n";

   p3 += p1; cout << "After p3 += p1, p3 is " << p3 << endl;
   p3 -= p2; cout << "After p3 -= p2, p3 is " << p3 << endl;
   p3 *= p1; cout << "After p3 *= p1, p3 is " << p3 << endl;

   return 0;
}
