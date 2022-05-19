// Exercise 12.11: Date.cpp

#include <iostream>
#include <string>

#include "Date.h"

using namespace std;

const array< unsigned int, 13 > Date::days{
   0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

ostream& operator<<( ostream& output, const Date& d ) {
   static string monthName[ 13 ]{ "", "January", "February",
      "March", "April", "May", "June", "July", "August",
      "September", "October", "November", "December" };
   output << monthName[ d.month ] << ' ' << d.day << ", " << d.year;
   return output;
}

Date::Date( int month, int day, int year ) {
   setDate( month, day, year );
}

Date& Date::operator++() {
   helpIncrement();
   return *this;
}

Date Date::operator++( int ) {
   Date temp{ *this };
   helpIncrement();
   return temp;
}

Date& Date::operator+=( unsigned int additionalDays ) {
   for ( unsigned int i = 0; i < additionalDays; ++i )
      helpIncrement();
   return *this;
}

void Date::setDate( int mm, int dd, int yy ) {

   if ( mm >= 1 && mm <= 12 )
      month = mm;
   else
      throw invalid_argument{ "Month must be 1-12" };

   if ( yy >= 1900 && yy <= 2100 )
      year = yy;
   else
      throw invalid_argument{ "Year must be >= 1900 and <= 2100" };

   if ( ( mm == 2 && leapYear( year ) && dd >= 1 && dd <= 29 )
        || ( dd >= 1 && dd <= days[ mm ] ) )
      day = dd;
   else
      throw invalid_argument{ "Day is out of range for current month and year" };
}

unsigned Date::getMonth() const {
   return month;
}

bool Date::leapYear( int testYear ) {
   return ( testYear % 400 == 0 || ( testYear % 100 != 0 && testYear % 4 == 0 ) );
}

bool Date::endOfMonth( int testDay ) const {
   if ( month == 2 && leapYear( year ) )
      return testDay == 29;
   else
      return testDay == days[ month ];
}

void Date::helpIncrement() {
   if ( !endOfMonth( day ) )
      day++;
   else {
      if ( month < 12 ) {
         month++;
         day = 1;
      }
      else {
         year++;
         month = 1;
         day = 1;
      }
   }
}