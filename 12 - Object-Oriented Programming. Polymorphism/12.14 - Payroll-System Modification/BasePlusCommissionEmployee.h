// Exercise 12.14: BasePlusCommissionEmployee.h

#ifndef BASEPLUSCOMMISSIONEMPLOYEE_H
#define BASEPLUSCOMMISSIONEMPLOYEE_H

#include <string>
#include "CommissionEmployee.h"

class BasePlusCommissionEmployee : public CommissionEmployee {

public:

   BasePlusCommissionEmployee(
      const std::string&, const std::string&, const std::string&, int, int, int,
      double = 0.0, double = 0.0, double = 0.0 );
   virtual ~BasePlusCommissionEmployee() = default;

   void setBaseSalary( double );
   double getBaseSalary() const;

   virtual double earnings() const override;
   virtual std::string toString() const override;

private:

   double baseSalary;
};

#endif