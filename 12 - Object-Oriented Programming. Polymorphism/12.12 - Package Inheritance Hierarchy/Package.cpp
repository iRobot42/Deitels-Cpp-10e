// Exercise 12.12: Package.cpp

#include <sstream>
#include "Package.h"

using namespace std;

Package::Package( const PData& S, const PData& R,
                  const double W, const double C )
   : sender{ S }, recipient{ R },
     weight{ W > 0.0 ? W : throw "Incorrect weight" },
     costPerOunce{ C > 0.0 ? C : throw "Incorrect cost" } {
}

double Package::getWeight() const { return weight; }
double Package::getCostPerOunce() const { return costPerOunce; }

double Package::calculateCost() const {
   return weight * costPerOunce;
}

string Package::getLabels() const {

   ostringstream output;

   output << "FROM: " << sender.name << '\n' << sender.address << ", "
      << sender.city << ", " << sender.state << ", " << sender.zip << "\nTO: "
      << recipient.name << '\n' << recipient.address << ", " << recipient.city
      << ", " << recipient.state << ", " << recipient.zip << endl;

   return output.str();
}