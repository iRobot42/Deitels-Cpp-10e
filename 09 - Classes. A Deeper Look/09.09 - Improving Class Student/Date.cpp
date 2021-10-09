// Exercise 9.9: Date.cpp
// Date class member-function definitions

#include <sstream>
#include <string>

#include "Date.h"

using namespace std;

Date::Date( unsigned int m, unsigned int d, unsigned int y ):
   month{ m }, day{ d }, year{ y } {}

void Date::setDay( unsigned int d ) { day = d; }
void Date::setMonth( unsigned int m ) { month = m; }
void Date::setYear( unsigned int y ) { year = y; }

string Date::toString() const {
   ostringstream output;
   output << month << '/' << day << '/' << year;
   return output.str();
}