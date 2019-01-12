// Exercise 6.32: ex_06_32.cpp

#include <iostream>

using namespace std;

int qualityPoints( int );

int main() {

   int average;

   do {
      cout << "Student's average: ";
      cin >> average;
   } while ( average < 0 || average > 100 );

   cout << "Quality point is " << qualityPoints( average ) << endl;

   return 0;
}

int qualityPoints( int x ) {

   if ( x >= 90 ) return 4;
   else if ( x >= 80 ) return 3;
   else if ( x >= 70 ) return 2;
   else if ( x >= 60 ) return 1;
   else return 0;
}
