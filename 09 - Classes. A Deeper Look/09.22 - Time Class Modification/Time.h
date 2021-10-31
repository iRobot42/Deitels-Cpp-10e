// Exercise 9.22: Time.h
// Member functions defined in Time.cpp

#ifndef TIME_H
#define TIME_H

#include <string>

class Time {

public:

   explicit Time( int = 0, int = 0, int = 0 );

   void setTime( int, int, int );
   void setHour( int );
   void setMinute( int );
   void setSecond( int );

   unsigned int getTime() const; // new
   unsigned int getHour() const;
   unsigned int getMinute() const;
   unsigned int getSecond() const;

   std::string toUniversalString() const;
   std::string toStandardString() const;

private:

   unsigned int time{};
};

#endif