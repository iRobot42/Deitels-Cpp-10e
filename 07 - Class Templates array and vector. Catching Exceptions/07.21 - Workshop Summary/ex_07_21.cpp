// Exercise 7.21: ex_07_21.cpp

#include <array>
#include <iostream>

using namespace std;

int main() {

   const size_t CP{ 3 + 1 }; // craftspeople
   const size_t PN{ 4 + 1 }; // product numbers
   array< array< int, PN >, CP > stock{};

   cout << "Enter slip's data (Person Product Items) [0 to end].\n" << endl;

   while ( true ) {

      size_t person;
      size_t product;
      int items;

      cout << "> ";
      cin >> person;
      if ( !person ) break;
      cin >> product >> items;

      if ( person < 1 || product < 1 || items < 0
         || person >= CP || product >= PN ) {
         cout << "Incorrect data. Try again." << endl;
         continue;
      }

      stock[ person ][ product ] += items;
   }

   cout << "\nProduct:";
   for ( size_t pn{ 1 }; pn < PN; ++pn )
      cout << '\t' << pn;
   cout << "\tTOTAL\n";

   for ( int i{ 0 }; i < 53; ++i ) cout << '-';

   for ( size_t row{ 1 }; row < CP; ++row ) {
      cout << "\nPerson " << row;
      for ( size_t col{ 1 }; col < PN; ++col ) {
         cout << '\t' << stock[ row ][ col ];

         stock[ row ][ 0 ] += stock[ row ][ col ];
         stock[ 0 ][ col ] += stock[ row ][ col ];
         stock[ 0 ][ 0 ] += stock[ row ][ col ]; // total items counter
      }
      cout << '\t' << stock[ row ][ 0 ];
   }

   cout << "\n\nTOTAL:\t";
   for ( size_t pn{ 1 }; pn < PN; ++pn )
      cout << '\t' << stock[ 0 ][ pn ];
   cout << '\t' << stock[ 0 ][ 0 ] << endl;
   
   return 0;
}
