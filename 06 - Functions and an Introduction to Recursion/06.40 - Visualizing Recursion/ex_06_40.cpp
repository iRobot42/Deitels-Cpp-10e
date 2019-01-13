// Exercise 6.40: ex_06_40.cpp

#include <iomanip>
#include <iostream>

using namespace std;

unsigned long factorial( int );

int main() {

   for ( int counter{ 0 }; counter <= 10; ++counter )
      cout << setw( 2 ) << counter << "! = " << factorial( counter )
         << "\n\n";

   return 0;
}

unsigned long factorial( int number ) {

   if ( number <= 1 ) // base cases branch
      return 1;
   else { // recursive call branch
      cout << setw( number ) // indentation
           << number - 1     // call parameter
           << endl;          // separate line
      return number * factorial( number - 1 );
   }
}
