// Exercise 9.19: Date.h
// Member functions defined in Date.cpp

#ifndef DATE_H
#define DATE_H

#include <array>
#include <string>

static const unsigned int MONTHS{ 12 };
static std::array< int, MONTHS + 1 > daysPerMonth{ 0,
   31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
static const std::array< std::string, MONTHS + 1 > MNAMES{ "",
   "January", "February", "March", "April", "May", "June", "July",
   "August", "September", "October", "November", "December" };

class Date {

public:

   Date();
   explicit Date( int, int );
   explicit Date( int, int, int );
   explicit Date( std::string, int, int );
   ~Date();

   std::string outputDDD() const; // DDD YYYY
   std::string outputMDY() const; // MM/DD/YY
   std::string outputMon() const; // Month D, YYYY

   void setDate( const int&, const int&, const int& );
   bool leapYear( const int& ) const;

private:

   unsigned int month;
   unsigned int day;
   unsigned int year;
};

#endif