// Exercise 3.11: MotorVehicle.h

#include <iostream>
#include <string>

class MotorVehicle {

public:

   MotorVehicle( std::string m, std::string ft, int y ) {
      setMake( m );
      setFuelType( ft );
      setYearOfManufacture( y );
   }

   void setMake( std::string m ) {
      make = m;
   }

   void setFuelType( std::string ft ) {
      fuelType = ft;
   }

   void setYearOfManufacture( int y ) {
      yearOfManufacture = y;
   }

   void setColor( std::string c ) {
      color = c;
   }

   void setEngineCapacity( int ec ) {
      engineCapacity = ec;
   }

   std::string getMake() const {
      return make;
   }

   std::string getFuelType() const {
      return fuelType;
   }

   int getYearOfManufacture() const {
      return yearOfManufacture;
   }

   std::string getColor() const {
      return color;
   }

   int getEngineCapacity() const {
      return engineCapacity;
   }

   void displayCarDetails() const {
      std::cout << "CAR DETAILS"
         << "\nMake:                " << make
         << "\nFuel type:           " << fuelType
         << "\nYear of manufacture: " << yearOfManufacture
         << "\nColor:               " << color
         << "\nEngine capacity:     " << engineCapacity
         << std::endl;
   }

private:

   std::string make;
   std::string fuelType;
   int yearOfManufacture;
   std::string color;
   int engineCapacity;
};
