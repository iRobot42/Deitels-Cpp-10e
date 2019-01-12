// Exercise 6.33: ex_06_33.cpp

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

inline bool flip( void ) { return rand() % 2; }

int main() {

   int heads{ 0 };
   int tails{ 0 };

   srand( time( 0 ) );

   for ( int i{ 1 }; i <= 100; ++i )
      flip() ? heads++ : tails++;

   cout << "Heads: " << heads
      << "\nTails: " << tails
      << endl;

   return 0;
}
