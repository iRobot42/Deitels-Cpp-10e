// Exercise 4.35: ex_04_35.cpp

#include <iostream>

using namespace std;

int main() {

// PART A

   int n{ -1 };
   int nFact{ 1 };

   while ( n < 0 ) {
      cout << "Nonnegative integer: ";
      cin >> n;
   }

   while ( n > 1 ) {
      nFact *= n;
      n--;
   }

   cout << "Factorial is " << nFact << endl;

// PART B

   n = 0;
   nFact = 1;   

   int accuracy;

   cout << "\nAccuracy: ";
   cin >> accuracy;

   double e{ 1.0 };

   while ( ++n <= accuracy ) {
      nFact *= n;
      e += 1.0 / nFact;
   }

   cout << "e is " << e << endl;

// PART C

   n = 0;
   nFact = 1;

   double x;

   cout << "\nx: ";
   cin >> x;

   double xn{ 1.0 };
   double ex{ 1.0 };

   while ( ++n <= accuracy ) {
      xn *= x;
      nFact *= n;
      ex += xn / nFact;
   }

   cout << "e^x is " << ex << endl;

   return 0;
}
