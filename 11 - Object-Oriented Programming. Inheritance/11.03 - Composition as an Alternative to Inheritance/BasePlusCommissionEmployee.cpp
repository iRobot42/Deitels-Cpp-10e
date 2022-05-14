// Exercise 11.3: BasePlusCommissionEmployee.cpp

#include <iomanip>
#include <sstream>
#include <stdexcept>

#include "BasePlusCommissionEmployee.h"

using namespace std;

BasePlusCommissionEmployee::BasePlusCommissionEmployee(
   string first, string last, string ssn,
   double sales, double rate, double salary )
   : commissionEmployee{ first, last, ssn, sales, rate } {
   setBaseSalary( salary );
}

void BasePlusCommissionEmployee::setBaseSalary( double salary ) {
   if ( salary < 0.0 )
      throw invalid_argument( "Salary must be >= 0.0" );
   baseSalary = salary;
}

string BasePlusCommissionEmployee::getFirstName() const {
   return commissionEmployee.getFirstName();
}

string BasePlusCommissionEmployee::getLastName() const {
   return commissionEmployee.getLastName();
}

string BasePlusCommissionEmployee::getSocialSecurityNumber() const {
   return commissionEmployee.getSocialSecurityNumber();
}

double BasePlusCommissionEmployee::getGrossSales() const {
   return commissionEmployee.getGrossSales();
}

double BasePlusCommissionEmployee::getCommissionRate() const {
   return commissionEmployee.getCommissionRate();
}

double BasePlusCommissionEmployee::getBaseSalary() const {
   return baseSalary;
}

double BasePlusCommissionEmployee::earnings() const {
   return getBaseSalary() + commissionEmployee.earnings();
}

string BasePlusCommissionEmployee::toString() const {

   ostringstream output;

   output << fixed << setprecision( 2 )
      << "base-salaried " << commissionEmployee.toString()
      << "\nbase salary: " << getBaseSalary();

   return output.str();
}