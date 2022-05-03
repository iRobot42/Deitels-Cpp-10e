// Exercise 10.8: MotorVehicle.cpp
// MotorVehicle class member-function definitions

#include <iostream>

#include "MotorVehicle.h"

using namespace std;

ostream& operator<<( ostream& output, const MotorVehicle& mv ) {
   output << "CAR DETAILS"
      << "\nMake:                " << mv.make
      << "\nFuel type:           " << mv.fuelType
      << "\nYear of manufacture: " << mv.yearOfManufacture
      << "\nColor:               " << mv.color
      << "\nEngine capacity:     " << mv.engineCapacity
      << endl;
   return output;
}

MotorVehicle::MotorVehicle( std::string m, std::string ft, int y,
                                     std::string c, int ec ) {
   setMake( m );
   setFuelType( ft );
   setYearOfManufacture( y );
   setColor( c );
   setEngineCapacity( ec );
}

MotorVehicle::MotorVehicle( const MotorVehicle& mv ) {
   setMake( mv.getMake() );
   setFuelType( mv.getFuelType() );
   setYearOfManufacture( mv.getYearOfManufacture() );
   setColor( mv.getColor() );
   setEngineCapacity( mv.getEngineCapacity() );
}

bool MotorVehicle::operator==( const MotorVehicle& mv ) const {
   if ( make != mv.make || fuelType != mv.fuelType || color != mv.color ||
        yearOfManufacture != mv.yearOfManufacture ||
        engineCapacity != mv.engineCapacity )
      return false;
   return true;
}

bool MotorVehicle::operator!=( const MotorVehicle& mv ) const {
   return !( *this == mv );
}

bool MotorVehicle::operator>( const MotorVehicle& mv ) const {
   return yearOfManufacture < mv.yearOfManufacture;
}

void MotorVehicle::setMake( std::string m ) {
   make = m;
}

void MotorVehicle::setFuelType( std::string ft ) {
   fuelType = ft;
}

void MotorVehicle::setYearOfManufacture( int y ) {
   yearOfManufacture = y;
}

void MotorVehicle::setColor( std::string c ) {
   color = c;
}

void MotorVehicle::setEngineCapacity( int ec ) {
   engineCapacity = ec;
}

std::string MotorVehicle::getMake() const {
   return make;
}

std::string MotorVehicle::getFuelType() const {
   return fuelType;
}

int MotorVehicle::getYearOfManufacture() const {
   return yearOfManufacture;
}

std::string MotorVehicle::getColor() const {
   return color;
}

int MotorVehicle::getEngineCapacity() const {
   return engineCapacity;
}