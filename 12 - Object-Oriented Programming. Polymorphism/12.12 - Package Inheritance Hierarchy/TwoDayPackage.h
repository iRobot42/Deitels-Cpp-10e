// Exercise 12.12: TwoDayPackage.h

#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include "Package.h"

class TwoDayPackage : public Package {

public:

   explicit TwoDayPackage( const PData&, const PData&,
                           const double, const double, const double );
   virtual ~TwoDayPackage() = default;

   virtual double calculateCost() const override;

private:

   double flatFee;
};

#endif