// Exercise 12.12: ex_12_12.cpp
// Package Inheritance Hierarchy

#include <iomanip>
#include <iostream>
#include <typeinfo>
#include <vector>

#include "TwoDayPackage.h"
#include "OvernightPackage.h"

using namespace std;

int main() {

   PData person1{ "Robot I.", "100-0042 Science Rd.", "Cogwheel", "0X", 10101 };
   PData person2{ "Bender R.", "57th St.", "New New York", "NY", 98765 };

   vector< Package* > packages{
      new TwoDayPackage{ person1, person2, 100.0, 1.0, 0.1 },
      new OvernightPackage{ person2, person1, 10.0, 2.0, 0.2 }
   };

   cout << fixed << setprecision( 2 );

   vector< double > costs{};

   for ( Package* packagePtr : packages ) {
      cout << typeid( *packagePtr ).name() << ":\n" << packagePtr->getLabels()
         << "Shipping cost: $" << packagePtr->calculateCost() << '\n' << endl;
      costs.push_back( packagePtr->calculateCost() );
   }

   double total{};

   for ( int i{}; i < costs.size(); ++i )
      total += costs[ i ];

   cout << "Total shipping cost is $" << total << endl;

   return 0;
}
