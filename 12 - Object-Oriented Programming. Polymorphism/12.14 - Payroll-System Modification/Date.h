// Exercise 12.14: Date.h

#ifndef DATE_H
#define DATE_H

#include <array>
#include <iostream>

class Date {

   friend std::ostream& operator<<( std::ostream&, const Date& );

public:

   Date( int m = 1, int d = 1, int y = 1900 );

   Date& operator++();
   Date operator++( int );
   Date& operator+=( unsigned int );

   void setDate( int, int, int );

   unsigned getMonth() const;

   static bool leapYear( int );
   bool endOfMonth( int ) const;

private:

   unsigned month;
   unsigned day;
   unsigned year;

   static const std::array< unsigned int, 13 > days;
   void helpIncrement();
};

#endif