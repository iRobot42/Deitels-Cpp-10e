// Exercise 6.25: ex_06_25.cpp

#include <cmath>
#include <iostream>

using namespace std;

int calculateMinutes( int, int, int );

int main() {

   int days, hours, minutes;

   cout << "Time (dd hh mm): ";
   cin >> days >> hours >> minutes;

   int time{ calculateMinutes( days, hours, minutes ) };

   cout << "Second time: ";
   cin >> days >> hours >> minutes;

   cout << "\nDifference between two times is "
      << fabs( time - calculateMinutes( days, hours, minutes ) )
      << " minute(s)." << endl;

   return 0;
}

int calculateMinutes( int d, int h, int m ) {
   return m + h * 60 + d * 1440;
}
