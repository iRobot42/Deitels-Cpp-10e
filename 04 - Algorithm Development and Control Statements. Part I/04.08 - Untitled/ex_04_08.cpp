// Exercise 4.8: ex_04_08.cpp

#include <iostream>
using namespace std;

int main() {

   cout << "x: ";
   unsigned int x;
   cin >> x;

   cout << "y: ";
   unsigned int y;
   cin >> y;

   unsigned int i{ 1 };
   unsigned int power{ 1 };

   while ( i <= y ) {
      power *= x;
      ++i;
   }

   cout << "Power is " << power;

   return 0;
}
