// Exercise 12.14: HourlyWorker.cpp

#include <iomanip>
#include <sstream>
#include <string>

#include "HourlyWorker.h"

using namespace std;

HourlyWorker::HourlyWorker( const string& first, const string& last,
                            const string& ssn, int month, int day, int year,
                            double w, unsigned h )
   : Employee{ first, last, ssn, month, day, year },
     wage{ w > 0.0 ? w : throw "Incorrect wage" }, hours{ h } {
}

double HourlyWorker::getWage() const {
   return wage;
}

unsigned HourlyWorker::getHours() const {
   return hours;
}

double HourlyWorker::earnings() const {
   return ( getHours() <= 40 ? getHours() * getWage() : 40 * getWage()
            + ( getHours() - 40 ) * getWage() * 1.5 );
}

string HourlyWorker::toString() const {

   ostringstream output;

   output << fixed << setprecision( 2 )
      << "hourly worker: " << Employee::toString()
      << "\nhours worked: " << getHours()
      << "; wage per hour: " << getWage();

   return output.str();
}