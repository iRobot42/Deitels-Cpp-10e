// Exercise 7.35: ex_07_35.cpp

#include <array>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main() {

   array< string, 5 > topics{ "Public Health", "Waste Disposal",
      "Climate Change", "Overpopulation", "Pollution" };

   array< array< int, 10 >, 5 > responses{};

   cout << "Please rate each of these global environmental issues (1-10):"
      << endl;

   char next{ 'y' };

   int number{};

   do {

      ++number;

      cout << endl;

      for ( int issue{}; issue < 5; ++issue ) {

         int rating;

         do {
            cout << topics[ issue ] << ": ";
            cin >> rating;
         } while ( rating < 1 || rating > 10 );

         ++responses[ issue ][ rating - 1 ];
      }

      cout << "\nNext respondent? (y/n): ";
      cin >> next;

   } while ( next != 'n' );

   cout << "\nRating:        ";
   for ( int i{ 1 }; i <= 10; ++i ) cout << setw( 4 ) << i;
   cout << "  Average" << endl;
   for ( int i{}; i < 64; ++i ) cout << '-';
   cout << endl;

   int total_min{ 10 * number };
   int total_max{};
   int issue_min;
   int issue_max;

   for ( int row{}; row < 5; ++row ) {
      
      cout << left << setw( 15 ) << topics[ row ];

      int total{};
      
      for ( int col{}; col < 10; ++col ) {
         cout << right << setw( 4 ) << responses[ row ][ col ];
         total += responses[ row ][ col ] * ( col + 1 );
      }

      if ( total < total_min ) {
         total_min = total;
         issue_min = row;
      }

      if ( total > total_max ) {
         total_max = total;
         issue_max = row;
      }

      cout << fixed << setprecision( 1 );
      cout << setw( 9 ) << 1.0 * total / number << endl;
   }

   cout << "\nHighest point total: " << topics[ issue_max ] << " ("
      << total_max << ")\nLowest point total: " << topics[ issue_min ] << " ("
      << total_min << ")" << endl;

   return 0;
}
