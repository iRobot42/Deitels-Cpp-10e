// Exercise 6.22: ex_06_22.cpp

#include <iostream>

using namespace std;

void displayRectangle( int, int );

int main() {

   int w, h;

   do {
      cout << "Width and height: ";
      cin >> w >> h;
   } while ( w < 1 || h < 1 );

   cout << endl;

   displayRectangle( w, h );

   return 0;
}

void displayRectangle( int width, int height ) {

   for ( int y{ 1 }; y <= height; ++y ) {
      for ( int x{ 1 }; x <= width; ++x )
         cout << '*';
      cout << endl;
   }
}
