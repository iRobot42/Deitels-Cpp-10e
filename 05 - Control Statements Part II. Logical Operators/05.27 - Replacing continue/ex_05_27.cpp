// Exercise 5.27: ex_05_27.cpp

#include <iostream>

using namespace std;

int main() {

   for ( unsigned int count{ 1 }; count <= 10; count++ ) {

      if ( count == 5 )
         ++count;

      cout << count << ' ';
   }

   cout << "\nUsed increment to skip printing 5" << endl;

   return 0;
}
