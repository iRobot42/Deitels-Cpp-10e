// Exercise 11.9: Package.cpp

#include "Package.h"

using namespace std;

Package::Package( const PData& S, const PData& R,
                  const double W, const double C )
   : sender{ S }, recipient{ R },
     weight{ W > 0.0 ? W : throw "Incorrect weight" },
     costPerOunce{ C > 0.0 ? C : throw "Incorrect cost" } {
}

const double Package::getWeight() const { return weight; }
const double Package::getCostPerOunce() const { return costPerOunce; }

const double Package::calculateCost() const {
   return weight * costPerOunce;
}