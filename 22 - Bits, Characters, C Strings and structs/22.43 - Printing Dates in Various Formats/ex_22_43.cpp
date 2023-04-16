// Exercise 22.43: ex_22_43.cpp
// Printing Dates in Various Formats

#include <iostream>
using namespace std;

void print( const char* c ) {

   const char months[][ 10 ]{ "", "January", "February", "March", "April", "May",
      "June", "July", "August", "September", "October", "November", "December" };

   cout << c << " : " << months[ atoi( c ) ] << ' '
      << atoi( c + 3 ) << ", " << atoi( c + 6 ) << endl;
}

int main() {

   print( "07/21/1955" );
   print( "12/09/0999" );

   return EXIT_SUCCESS;
}
