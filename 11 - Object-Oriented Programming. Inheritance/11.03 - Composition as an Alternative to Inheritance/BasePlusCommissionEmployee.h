// Exercise 11.3: BasePlusCommissionEmployee.h

#ifndef BASEPLUS_H
#define BASEPLUS_H

#include <string>
#include "CommissionEmployee.h"

class BasePlusCommissionEmployee {

public:

   BasePlusCommissionEmployee( std::string, std::string, std::string,
                               double = 0.0, double = 0.0, double = 0.0 );

   void setBaseSalary( double );

   std::string getFirstName() const;
   std::string getLastName() const;
   std::string getSocialSecurityNumber() const;
   double getGrossSales() const;
   double getCommissionRate() const;
   double getBaseSalary() const;

   double earnings() const;
   std::string toString() const;

private:

   CommissionEmployee commissionEmployee;
   double baseSalary;
};

#endif