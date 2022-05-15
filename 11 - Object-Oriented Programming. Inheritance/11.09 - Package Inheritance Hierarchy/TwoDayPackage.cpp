// Exercise 11.9: TwoDayPackage.cpp

#include "TwoDayPackage.h"

TwoDayPackage::TwoDayPackage( const PData& S, const PData& R,
                              const double W, const double C, const double F )
   : Package( S, R, W, C ), flatFee{ F > 0 ? F : throw "Incorrect fee" } {
}

const double TwoDayPackage::calculateCost() const {
   return Package::calculateCost() + flatFee;
}