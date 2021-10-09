// Exercise 9.10: Date.h
// Member functions defined in Date.cpp

#include <string>

#ifndef DATE_H
#define DATE_H

class Date {

public:

   explicit Date( unsigned int = 1, unsigned int = 1, unsigned int = 2000 );

   void setDay( unsigned int );
   void setMonth( unsigned int );
   void setYear( unsigned int );

   std::string toString() const;

private:

   unsigned int day;
   unsigned int month;
   unsigned int year;
};

#endif