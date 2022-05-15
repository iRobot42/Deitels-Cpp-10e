// Exercise 11.9: OvernightPackage.h

#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

#include "Package.h"

class OvernightPackage : public Package {

public:

   explicit OvernightPackage( const PData&, const PData&,
                              const double, const double, const double );

   const double calculateCost() const;

private:

   double fee;
};

#endif