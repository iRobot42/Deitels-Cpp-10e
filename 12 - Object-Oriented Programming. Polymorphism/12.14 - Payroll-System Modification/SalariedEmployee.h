// Exercise 12.14: SalariedEmployee.h

#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

#include <string>
#include "Employee.h"

class SalariedEmployee : public Employee {

public:

   SalariedEmployee(
      const std::string&, const std::string&, const std::string&, int, int, int,
      double = 0.0 );
   virtual ~SalariedEmployee() = default;

   void setWeeklySalary( double );
   double getWeeklySalary() const;

   virtual double earnings() const override;
   virtual std::string toString() const override;

private:

   double weeklySalary;
};

#endif