// Exercise 4.30: ex_04_30.cpp

#include <iostream>

using namespace std;

int main() {

   unsigned n1{ 0 };
   unsigned n2{ 1 };

   cout << n1 << '\n' << n2 << endl;

   while ( true ) {

      unsigned temp = n1 + n2;
      
      cout << temp << endl;

      n1 = n2;
      n2 = temp;
   }

   return 0;
}
