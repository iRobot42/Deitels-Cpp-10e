// Exercise 10.8: ex_10_08.cpp
// Enhanced MotorVehicle Class

#include <iostream>
#include "MotorVehicle.h"

using namespace std;

int main() {

   MotorVehicle car1( "Mercedes-Benz", "Hybrid", 2015, "Jade Green", 1600 );
   MotorVehicle car2( "Ferrari", "Gasoline", 2000, "Rosso Monza", 3600 );

   cout << car1 << endl << car2 << endl;

   if ( car1 != car2 )
      cout << "Motor vehicles car1 and car2 are not identical" << endl;
   if ( car2 > car1 )
      cout << "Motor vehicle car2 was manufactured before car1\n" << endl;

   MotorVehicle car3( car1 );

   cout << car3 << endl;

   if ( car3 == car1 )
      cout << "Motor vehicles car1 and car3 are identical" << endl;

   return 0;
}
