// Exercise 11.3: CommissionEmployee.h

#ifndef COMMISSION_H
#define COMMISSION_H

#include <string>

class CommissionEmployee {

public:

   CommissionEmployee( const std::string&, const std::string&,
                       const std::string&, double = 0.0, double = 0.0 );

   void setFirstName( const std::string& );
   void setLastName( const std::string& );
   void setSocialSecurityNumber( const std::string& );
   void setGrossSales( double );
   void setCommissionRate( double );

   std::string getFirstName() const;
   std::string getLastName() const;
   std::string getSocialSecurityNumber() const;
   double getGrossSales() const;
   double getCommissionRate() const;

   double earnings() const;
   std::string toString() const;

private:

   std::string firstName;
   std::string lastName;
   std::string socialSecurityNumber;
   double grossSales;
   double commissionRate;
};

#endif