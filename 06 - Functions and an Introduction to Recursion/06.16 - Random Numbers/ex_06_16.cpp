// Exercise 6.16: ex_06_16.cpp

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>

using namespace std;

int main() {

   int n;

   srand( time( 0 ) );

   n = rand() % 4;          // a
   n = 1 + rand() % 50;     // b
   n = 2 + rand() % 43;     // c
   n = 500 + rand() % 179;  // d
   n = -2 + rand() % 5;     // e
   n = -3 + rand() % 16;    // f

   // C++11

   default_random_engine generator{ static_cast< unsigned int >( time( 0 ) ) };
   
   uniform_int_distribution< int > na{ 0, 3 };      // a
   uniform_int_distribution< int > nb{ 1, 50 };     // b
   uniform_int_distribution< int > nc{ 2, 44 };     // c
   uniform_int_distribution< int > nd{ 500, 678 };  // d
   uniform_int_distribution< int > ne{ -2, 2 };     // e
   uniform_int_distribution< int > nf{ -3, 12 };    // f

   // TEST

   for ( int i{ 1 }; i <= 100; ++i ) {
      n = nf( generator );
      cout << n << endl;
   }

   return 0;
}
