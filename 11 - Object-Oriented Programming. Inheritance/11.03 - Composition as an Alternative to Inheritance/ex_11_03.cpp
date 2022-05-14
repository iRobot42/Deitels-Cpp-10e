// Exercise 11.3: ex_11_03.cpp
// Composition as an Alternative to Inheritance

#include <iomanip>
#include <iostream>

#include "BasePlusCommissionEmployee.h"

using namespace std;

int main() {

   BasePlusCommissionEmployee employee{ "Bob", "Lewis", "333-33-3333",
      5000, .04, 300 };

   cout << fixed << setprecision( 2 )
      << "Employee information obtained by get functions:\n"
      << "\nFirst names is " << employee.getFirstName()
      << "\nLast name is " << employee.getLastName()
      << "\nSocial security number is " << employee.getSocialSecurityNumber()
      << "\nGross sales is " << employee.getGrossSales()
      << "\nCommission rate is " << employee.getCommissionRate()
      << "\nBase salary is " << employee.getBaseSalary() << endl;

   employee.setBaseSalary( 1000 );

   cout << "\nUpdated employee information from function toString:\n\n"
      << employee.toString() << "\n\nEmployee's earnings: $"
      << employee.earnings() << endl;

   return 0;
}
