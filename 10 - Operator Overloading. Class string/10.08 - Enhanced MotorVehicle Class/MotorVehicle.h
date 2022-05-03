// Exercise 10.8: MotorVehicle.h
// Member functions defined in MotorVehicle.cpp

#ifndef MOTORVEHICLE_H
#define MOTORVEHICLE_H

#include <string>

class MotorVehicle {

   friend std::ostream& operator<<( std::ostream&, const MotorVehicle& );

public:

   explicit MotorVehicle( std::string, std::string, int, std::string, int );
   MotorVehicle( const MotorVehicle& );

   bool operator==( const MotorVehicle& ) const;
   bool operator!=( const MotorVehicle& ) const;
   bool operator>( const MotorVehicle& ) const;

   void setMake( std::string );
   void setFuelType( std::string );
   void setYearOfManufacture( int );
   void setColor( std::string );
   void setEngineCapacity( int );

   std::string getMake() const;
   std::string getFuelType() const;
   int getYearOfManufacture() const;
   std::string getColor() const;
   int getEngineCapacity() const;

private:

   std::string make;
   std::string fuelType;
   int yearOfManufacture;
   std::string color;
   int engineCapacity;
};

#endif