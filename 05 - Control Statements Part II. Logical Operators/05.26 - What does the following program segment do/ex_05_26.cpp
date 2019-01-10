// Exercise 5.26: ex_05_26.cpp

#include <iostream>

using namespace std;

int main() {

   for ( unsigned int i{ 1 }; i <= 2; i++ ) {
      
      cout << i << " : ";
      
      for ( unsigned int j{ 1 }; j <= 3; j++ ) {
         
         for ( unsigned int k{ 4 }; k >= 2; k-- ) {
            cout << k;
         }

         cout << "-" << j << endl;
      }
   }

   cout << endl;
   return 0;
}
