// Exercise 11.9: ex_11_09.cpp
// Package Inheritance Hierarchy

#include <iomanip>
#include <iostream>

#include "TwoDayPackage.h"
#include "OvernightPackage.h"

using namespace std;

int main() {

   PData sender{ "Robot I.", "100-0042 Science Rd.", "Cogwheel", "0X", 10101 };
   PData recipient{ "Bender R.", "57th St.", "New New York", "NY", 98765 };

   Package package{ sender, recipient, 1.0, 4.2 };
   TwoDayPackage two_day_package{ sender, recipient, 100.0, 1.0, 0.1 };
   OvernightPackage overnight_package{ sender, recipient, 10.0, 2.0, 0.2 };

   cout << fixed << setprecision( 2 )
      << "Package: $" << package.calculateCost() << endl
      << "TwoDayPackage: $" << two_day_package.calculateCost() << endl
      << "OvernightPackage: $" << overnight_package.calculateCost() << endl;

   return 0;
}
