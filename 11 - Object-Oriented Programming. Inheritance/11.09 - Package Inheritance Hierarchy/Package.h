// Exercise 11.9: Package.h

#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>

struct PData {
   std::string name;
   std::string address;
   std::string city;
   std::string state;
   unsigned zip;
};

class Package {

public:

   explicit Package( const PData&, const PData&, const double, const double );

   const double getWeight() const;
   const double getCostPerOunce() const;

   const double calculateCost() const;

private:

   PData sender;
   PData recipient;
   double weight;
   double costPerOunce;
};

#endif