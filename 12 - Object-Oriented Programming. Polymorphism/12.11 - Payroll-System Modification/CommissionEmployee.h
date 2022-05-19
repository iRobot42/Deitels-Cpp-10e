// Exercise 12.11: CommissionEmployee.h

#ifndef COMMISSIONEMPLOYEE_H
#define COMMISSIONEMPLOYEE_H

#include <string>
#include "Employee.h"

class CommissionEmployee : public Employee {

public:

   CommissionEmployee(
      const std::string&, const std::string&, const std::string&, int, int, int,
      double = 0.0, double = 0.0 );
   virtual ~CommissionEmployee() = default;

   void setCommissionRate( double );
   void setGrossSales( double );

   double getCommissionRate() const;
   double getGrossSales() const;

   virtual double earnings() const override;
   virtual std::string toString() const override;

private:

   double grossSales;
   double commissionRate;
};

#endif