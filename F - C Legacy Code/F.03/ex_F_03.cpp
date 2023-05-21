// Exercise F.3: ex_F_03.cpp

#include <iostream>
using namespace std;

int main( int argc, char** argv ) {

   // 42 Robot $&#%

   cout << "Command-line arguments: ";
   for ( int i{ 1 }; i < argc; ++i )
      cout << argv[ i ] << ' ';
   cout << endl;

   return EXIT_SUCCESS;
}
