// Exercise 11.9: TwoDayPackage.h

#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include "Package.h"

class TwoDayPackage : public Package {

public:

   explicit TwoDayPackage( const PData&, const PData&,
                           const double, const double, const double );

   const double calculateCost() const;

private:

   double flatFee;
};

#endif