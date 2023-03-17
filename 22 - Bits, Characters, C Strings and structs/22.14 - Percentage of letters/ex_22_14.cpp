// Exercise 22.14: ex_22_14.cpp
// Percentage of letters

#include <iostream>
using namespace std;

int main() {

   const int SIZE{ 100 };
   char s[ SIZE ]{};

   cout << "Line of text: ";
   cin.getline( s, SIZE );

   int upper{}, lower{};

   for ( const auto CHAR : s )
      if ( isupper( CHAR ) )
         upper++;
      else if ( islower( CHAR ) )
         lower++;

   cout << "Uppercase: " << SIZE / 100.0 * upper << " %"
      << "\nLowercase: " << SIZE / 100.0 * lower << " %" << endl;

   return EXIT_SUCCESS;
}
