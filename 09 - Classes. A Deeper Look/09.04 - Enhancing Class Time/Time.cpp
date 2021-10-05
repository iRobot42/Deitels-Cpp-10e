// Exercise 9.4: Time.cpp
// Time class member-function definitions

#include <ctime>
#include <iomanip>
#include <sstream>
#include <stdexcept>

#include "Time.h"

using namespace std;

Time::Time( int hr, int min, int sec ) {
   setTime( hr, min, sec );
}

Time::Time( time_t time ) {
   struct tm local;
   localtime_s( &local, &time );
   setTime( local.tm_hour, local.tm_min, local.tm_sec );
}

Time& Time::setTime( int h, int m, int s ) {
   setHour( h ).setMinute( m ).setSecond( s );
   return *this;
}

Time& Time::setHour( int h ) {
   if ( h >= 0 && h < 24 ) hour = h;
   else throw invalid_argument( "hour must be 0-23" );
   return *this;
}

Time& Time::setMinute( int m ) {
   if ( m >= 0 && m < 60 ) minute = m;
   else throw invalid_argument( "minute must be 0-59" );
   return *this;
}

Time& Time::setSecond( int s ) {
   if ( s >= 0 && s < 60 ) second = s;
   else throw invalid_argument( "second must be 0-59" );
   return *this;
}

unsigned int Time::getHour() const { return hour; }

unsigned int Time::getMinute() const { return minute; }

unsigned int Time::getSecond() const { return second; }

string Time::toUniversalString() const {
   ostringstream output;
   output << setfill( '0' ) << setw( 2 ) << getHour() << ':'
      << setw( 2 ) << getMinute() << ':' << setw( 2 ) << getSecond();
   return output.str();
}

string Time::toStandardString() const {
   ostringstream output;
   output << ( ( getHour() == 0 || getHour() == 12 ) ? 12 : getHour() % 12 )
      << ':' << setfill( '0' ) << setw( 2 ) << getMinute() << ':' << setw( 2 )
      << getSecond() << ( hour < 12 ? " AM" : " PM" );
   return output.str();
}