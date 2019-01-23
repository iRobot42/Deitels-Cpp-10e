// Exercise 7.30: ex_07_30.cpp

#include <array>
#include <iostream>

using namespace std;

const int SIZE{ 5 };

void printArray( const array< int, SIZE >& A, int s, int e ) {   
   cout << A[ s ] << ' ';
   if ( s < e )
      printArray( A, s + 1, e );
}

int main() {

   const array< int, ::SIZE > TEST{ 1, 2, 3, 4, 5 };

   printArray( TEST, 0, 4 );
   
   cout << endl;
   return 0;
}
