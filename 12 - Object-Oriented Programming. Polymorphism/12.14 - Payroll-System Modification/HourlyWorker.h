// Exercise 12.14: HourlyWorker.h

#ifndef HOURLYWORKER_H
#define HOURLYWORKER_H

#include "Employee.h"

class HourlyWorker : public Employee {

public:

   HourlyWorker( const std::string&, const std::string&, const std::string&,
                 int, int, int, double, unsigned );
   virtual ~HourlyWorker() = default;

   double getWage() const;
   unsigned getHours() const;

   virtual double earnings() const override;
   virtual std::string toString() const override;

private:

   double wage;
   unsigned hours;
};

#endif