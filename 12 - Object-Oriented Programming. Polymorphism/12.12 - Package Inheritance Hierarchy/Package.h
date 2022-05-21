// Exercise 12.12: Package.h

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
   virtual ~Package() = default;

   double getWeight() const;
   double getCostPerOunce() const;

   virtual double calculateCost() const;
   std::string getLabels() const;

private:

   PData sender;
   PData recipient;
   double weight;
   double costPerOunce;
};

#endif