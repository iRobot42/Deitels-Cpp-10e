// Exercise 7.10: ex_07_10.cpp

#include <array>
#include <iostream>
#include <string>

using namespace std;

int main() {

   string currency;
   int rate;
 
   cout << "Currency and basic rate: ";
   cin >> currency >> rate;

   cout << "Hours worked and tips received (0 to end):\n";

   array< int, 9 > ranges{};

   while ( true ) {

      int hours;
      int tips;

      cout << "> ";
      cin >> hours;

      if ( !hours ) break;

      cin >> tips;

      int salary{ hours * rate + tips };

      if ( salary < 20 )
         continue;
      else if ( salary >= 100 )
         ++ranges[ 8 ];
      else
         ++ranges[ salary / 10 - 2 ];
   }

   cout << "\nIncome, " << currency << "\tServers\n-----------------------\n";

   for ( size_t range{ 0 }; range < ranges.size() - 1; ++range )
      cout << ( range + 2 ) * 10 << '-' << ( range + 2 ) * 10 + 9 << "\t\t"
         << ranges[ range ] << endl;
   cout << "100 and over:\t" << ranges[ 8 ] << endl;

   return 0;
}
