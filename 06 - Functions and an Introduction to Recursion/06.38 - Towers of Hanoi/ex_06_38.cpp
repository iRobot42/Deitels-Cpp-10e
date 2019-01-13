// Exercise 6.38: ex_06_38.cpp

#include <iostream>

using namespace std;

void hanoi( int, int, int, int );

int main() {

   int d;

   do {
      cout << "Number of disks: ";
      cin >> d;
   } while ( d < 1 );

   hanoi( d, 1, 3, 2 );

   return 0;
}

void hanoi( int disks, int from, int to, int temp ) {

   if ( disks ) {
      hanoi( disks - 1, from, temp, to );
      cout << from << " -> " << to << endl;
      hanoi( disks - 1, temp, to, from );
   }
}
