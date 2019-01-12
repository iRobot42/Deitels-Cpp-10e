// Exercise 6.23: ex_06_23.cpp

#include <iostream>

using namespace std;

void displayRectangle( int, int, char );

int main() {

   int w, h;
   char c;

   do {
      cout << "Width and height: ";
      cin >> w >> h;
   } while ( w < 1 || h < 1 );   

   cout << "Fill character: ";
   cin >> c;

   cout << endl;

   displayRectangle( w, h, c );

   return 0;
}

void displayRectangle( int width, int height, char fillCharacter ) {

   for ( int y{ 1 }; y <= height; ++y ) {
      for ( int x{ 1 }; x <= width; ++x )
         cout << fillCharacter;
      cout << endl;
   }
}
