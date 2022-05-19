// Exercise 12.11: ex_12_11.cpp
// Payroll-System Modification

#include <iomanip>
#include <iostream>
#include <typeinfo>
#include <vector>

#include "Employee.h"
#include "SalariedEmployee.h"
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"

using namespace std;

const int CURRENT_MONTH{ 5 }; // test

int main() {

   cout << fixed << setprecision( 2 );

   vector< Employee* > employees{
      new SalariedEmployee(
         "John", "Smith", "111-11-1111", 5, 1, 1990, 800 ),
      new CommissionEmployee(
         "Sue", "Jones", "333-33-3333", 2, 29, 2000, 10000, .06 ),
      new BasePlusCommissionEmployee(
         "Bob", "Lewis", "444-44-4444", 12, 31, 1999, 5000, .04, 300 ) };

   for ( Employee* employeePtr : employees ) {

      cout << employeePtr->toString() << endl;

      BasePlusCommissionEmployee* derivedPtr{
         dynamic_cast< BasePlusCommissionEmployee* >( employeePtr ) };

      if ( derivedPtr ) {
         derivedPtr->setBaseSalary( 1.1 * derivedPtr->getBaseSalary() );
         cout << "new base salary with 10% increase is: $"
            << derivedPtr->getBaseSalary() << endl;
      }

      if ( employeePtr )
         cout << "earned $" << employeePtr->earnings() +
            ( employeePtr->getBirthDate().getMonth() == ::CURRENT_MONTH ?
              100.0 : 0.0 ) << "\n\n";
   }

   for ( const Employee* employeePtr : employees ) {
      cout << "deleting object of " << typeid( *employeePtr ).name() << endl;
      delete employeePtr;
   }
}
