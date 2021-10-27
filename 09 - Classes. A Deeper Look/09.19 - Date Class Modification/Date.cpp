// Exercise 9.19: Date.cpp
// Date class member-function definitions

#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>

#include "Date.h"

using namespace std;

Date::Date() {

   time_t t{ time( 0 ) };
   struct tm local;

   localtime_s( &local, &t );

   setDate( local.tm_mon + 1, local.tm_mday, local.tm_year + 1900 );
   cout << "Date object constructor for current local date" << endl;
}

Date::Date( int m, int d, int y ) {
   setDate( m, d, y );
   cout << "Date object constructor for date " << outputMDY() << endl;
}

Date::Date( int d, int y ) {

   if ( d < 1 || d > ( leapYear( y ) ? 366 : 365 ) ) throw( "invalid day" );

   int m{ 1 };

   daysPerMonth[ 2 ] = ( leapYear( y ) ? 29 : 28 );
   while ( d > daysPerMonth[ m ] ) d -= daysPerMonth[ m++ ];

   setDate( m, d, y );
   cout << "Date object constructor for date " << outputDDD() << endl;
}

Date::Date( string s, int d, int y ) {

   int m{};

   for ( size_t i{ 1 }; i <= MONTHS; ++i )
      if ( MNAMES[ i ] == s ) {
         m = i;
         break;
      }

   m ? setDate( m, d, y ) : throw( "invalid month name" );
   cout << "Date object constructor for date " << outputMon() << endl;
}

Date::~Date() {
   //cout << "Date object destructor for date " << outputMDY() << endl;
}

string Date::outputDDD() const {

   ostringstream output;
   unsigned days{};

   daysPerMonth[ 2 ] = ( leapYear( year ) ? 29 : 28 );
   for ( size_t m{ 1 }; m < month; ++m ) days += daysPerMonth[ m ];
   days += day;

   output << days << ' ' << year;
   return output.str();
}

string Date::outputMDY() const {

   ostringstream output;

   output << setfill('0')
      << setw( 2 ) << month << '/'
      << setw( 2 ) << day << '/'
      << setw( 2 ) << year % 100;

   return output.str();
}

string Date::outputMon() const {

   ostringstream output;
   output << MNAMES[ month ] << ' ' << day << ", " << year;
   return output.str();
}

void Date::setDate( const int& M, const int& D, const int& Y ) {

   year = Y;
   daysPerMonth[ 2 ] = ( leapYear( Y ) ? 29 : 28 );

   if ( M < 1 || M > MONTHS ) throw( "month must be 1-12" );
   else month = M;

   if ( D > 0 && D <= daysPerMonth[ M ] ) day = D;
   else throw( "invalid day for current month and year" );
}

bool Date::leapYear( const int& Y ) const {
   return !( Y % 400 ) || ( !( Y % 4 ) && Y % 100 );
}