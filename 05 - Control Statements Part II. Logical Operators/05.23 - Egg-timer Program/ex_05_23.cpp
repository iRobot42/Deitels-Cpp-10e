// Exercise 5.23: ex_05_23.cpp

#include <iostream>

using namespace std;

int main() {

   int ast{ 9 }; // asterisks

   for ( int y{ 1 }; y <= 9; ++y ) {

      for ( int x{ 1 }; x <= 9; ++x ) {

         if ( x == 1 || y == 1 || x == 9 || y == 9 )
            cout << '#';
         else {

            for ( int x{ 1 }; x < ( 9 - ast ) / 2; ++x )
               cout << ' ';
            for ( int x{ 1 }; x <= ast; ++x )
               cout << '*';
            for ( int x{ 1 }; x < ( 9 - ast ) / 2; ++x )
               cout << ' ';

            x = 8;
         }
      }

      y < 5 ? ast -= 2 : ast += 2;

      cout << '\n';
   }

   return 0;
}
