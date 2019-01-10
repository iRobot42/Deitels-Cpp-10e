// Exercise 4.16: ex_04_16.cpp

#include <iomanip>
#include <iostream>

using namespace std;

int main() {

   int laps;

   cout << "Enter laps completed (-1 to end): ";
   cin >> laps;

   cout << setprecision( 2 ) << fixed;

   double contribution;
   double total_funds{ 0 };

   while ( laps != -1 ) {

      double rate;

      cout << "Enter sponsorship rate: ";
      cin >> rate;
      
      contribution = ( laps <= 40 ? laps * rate :
         40 * rate + ( laps - 40 ) * rate * 1.5 );

      total_funds += contribution;

      cout << "Student contribution is: " << contribution
         << "\n\nEnter laps completed (-1 to end): ";
      cin >> laps;
   }

   cout << "Total funds raised: " << total_funds << endl;

   return 0;
}
