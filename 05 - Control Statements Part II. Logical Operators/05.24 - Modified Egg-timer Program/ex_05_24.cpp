// Exercise 5.24: ex_05_24.cpp

#include <iostream>

using namespace std;

int main() {

   int size;

   do {
      cout << "Height (1-29, odd): ";
      cin >> size;
   } while ( size < 1 || size > 29 || size % 2 == 0 );

   int ast{ size }; // asterisks

   for ( int y{ 1 }; y <= size; ++y ) {
      
      for ( int x{ 1 }; x <= size; ++x ) {
      
         if ( x == 1 || y == 1 || x == size || y == size )
            cout << '#';
         else {
            
            for ( int i{ 1 }; i < ( size - ast ) / 2; ++i )
               cout << ' ';            
            for ( int i{ 1 }; i <= ast; ++i )
               cout << '*';            
            for ( int i{ 1 }; i < ( size - ast ) / 2; ++i )
               cout << ' ';

            x = size - 1;
         }
      }

      y <= size / 2 ? ast -= 2 : ast += 2;

      cout << '\n';
   }

   return 0;
}
