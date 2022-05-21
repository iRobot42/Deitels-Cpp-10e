// Exercise 12.12: OvernightPackage.h

#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

#include "Package.h"

class OvernightPackage : public Package {

public:

  explicit OvernightPackage( const PData&, const PData&,
                             const double, const double, const double );
   virtual ~OvernightPackage() = default;

   virtual double calculateCost() const override;

private:

   double fee;
};

#endif