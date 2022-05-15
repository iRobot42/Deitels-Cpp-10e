// Exercise 11.9: OvernightPackage.cpp

#include "OvernightPackage.h"

OvernightPackage::OvernightPackage( const PData& S, const PData& R,
                                    const double W, const double C,
                                    const double F )
   : Package( S, R, W, C ), fee{ F > 0 ? F : throw "Incorrect fee" } {
}

const double OvernightPackage::calculateCost() const {
   return Package::getWeight() * ( Package::getCostPerOunce() + fee );
}