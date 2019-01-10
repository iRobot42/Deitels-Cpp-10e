// Exercise 5.25: ex_05_25.cpp

#include <iostream>

using namespace std;

int main() {

   unsigned int count;
   bool flag = true;

   for ( count = 1; count <= 10 && flag; ++count ) {

      if ( count == 4 )
         flag = false;

      cout << count << ' ';
   }

   cout << "\nBroke out of loop at count = " << count << endl;

   return 0;
}
