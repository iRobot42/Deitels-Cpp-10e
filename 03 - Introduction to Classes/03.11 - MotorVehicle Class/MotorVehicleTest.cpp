// Exercise 3.11: MotorVehicleTest.cpp

#include <iostream>
#include "MotorVehicle.h"

using namespace std;

int main() {

   MotorVehicle motorVehicle( "Mercedes", "Diesel", 2010 );

   cout << "INITIAL ";
   motorVehicle.displayCarDetails();

   motorVehicle.setMake( "Mercedes-Benz" );
   motorVehicle.setFuelType( "Hybrid" );
   motorVehicle.setYearOfManufacture( 2015 );
   motorVehicle.setColor( "Green" );
   motorVehicle.setEngineCapacity( 1600 );

   cout << "\nMODIFIED ";
   motorVehicle.displayCarDetails();

   return 0;
}
