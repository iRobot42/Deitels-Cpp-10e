// Exercise 12.14: Employee.h

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "Date.h"

class Employee {

public:

   Employee( const std::string&, const std::string&, const std::string&,
             int, int, int );
   virtual ~Employee() = default;

   void setFirstName( const std::string& );
   void setLastName( const std::string& );
   void setSocialSecurityNumber( const std::string& );

   std::string getFirstName() const;
   std::string getLastName() const;
   std::string getSocialSecurityNumber() const;
   Date getBirthDate() const;

   virtual double earnings() const = 0;
   virtual std::string toString() const;

private:

   std::string firstName;
   std::string lastName;
   std::string socialSecurityNumber;
   Date birthDate;
};

#endif