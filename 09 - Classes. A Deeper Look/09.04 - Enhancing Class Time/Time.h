// Exercise 9.4: Time.h
// Time class definition. Member functions defined in Time.cpp

#include <string>

#ifndef TIME_H
#define TIME_H

class Time {

public:

   explicit Time( int = 0, int = 0, int = 0 );
   explicit Time( time_t );

   Time& setTime( int, int, int );
   Time& setHour( int );
   Time& setMinute( int );
   Time& setSecond( int );

   unsigned int getHour() const;
   unsigned int getMinute() const;
   unsigned int getSecond() const;
   
   std::string toUniversalString() const;
   std::string toStandardString() const;

private:

   unsigned int hour{ 0 };
   unsigned int minute{ 0 };
   unsigned int second{ 0 };
};

#endif