// Exercise 4.38: ex_04_38.cpp

#include <iomanip>
#include <iostream>

using namespace std;

int main() {

   double wp{ 7620.661 }; // world population, mil
   double ypg{ 83.297 };  // yearly population growth, mil
   double gr{ ypg / wp }; // growth rate

   cout << setprecision( 2 ) << fixed
      << "Growth rate: " << gr * 100 << " %\n\n"
      << "Year\tAWP(b)\tGrowth(m)\n\n";

   int year{ 2018 };

   while ( year <= 2018 + 75 ) {

      double awp{ wp + wp * gr }; // anticipated world population
      double growth{ awp - wp };

      cout << year++ << '\t' << awp / 1000 << '\t' << growth << endl;

      wp = awp;
   }

   return 0;
}
