// Exercise 4.12: Mystery.cpp
#include <iostream>
using namespace std;

int main() {
   unsigned int x{ 1 };
   unsigned int total{ 0 };

   while ( x <= 10 ) {
      int y = x * x;
      cout << y << endl;
      total += y;
      ++x;
   }

   cout << "Total is " << total << endl;
}
