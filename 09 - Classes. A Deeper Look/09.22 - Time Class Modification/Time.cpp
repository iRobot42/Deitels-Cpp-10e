// Exercise 9.22: Time.cpp
// Time class member-function definitions

#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <string>

#include "Time.h"

using namespace std;

Time::Time( int hour, int minute, int second ) {
   setTime( hour, minute, second );
}

void Time::setTime( int h, int m, int s ) {
   setHour( h );
   setMinute( m );
   setSecond( s );
}

void Time::setHour( int h ) {
   if ( h >= 0 && h < 24 ) time += ( h - getHour() ) * 3600;
   else throw invalid_argument( "hour must be 0-23" );
}

void Time::setMinute( int m ) {
   if ( m >= 0 && m < 60 ) time += ( m - getMinute() ) * 60;
   else throw invalid_argument( "minute must be 0-59" );
}

void Time::setSecond( int s ) {
   if ( s >= 0 && s < 60 ) time += ( s - getSecond() );
   else throw invalid_argument( "second must be 0-59" );
}

unsigned int Time::getTime() const { return time; }
unsigned int Time::getHour() const { return time / 3600; }
unsigned int Time::getMinute() const { return time % 3600 / 60; }
unsigned int Time::getSecond() const { return time % 60; }

string Time::toUniversalString() const {
   ostringstream output;
   output << setfill( '0' ) << setw( 2 ) << getHour() << ":"
      << setw( 2 ) << getMinute() << ":" << setw( 2 ) << getSecond();
   return output.str();
}

string Time::toStandardString() const {
   ostringstream output;
   output << ( ( getHour() == 0 || getHour() == 12 ) ? 12 : getHour() % 12 )
      << ":" << setfill( '0' ) << setw( 2 ) << getMinute() << ":" << setw( 2 )
      << getSecond() << ( getHour() < 12 ? " AM" : " PM" );
   return output.str();
}