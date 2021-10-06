// Exercise 9.6: Rational.h
// Rational class definition. Member functions defined in Rational.cpp

#ifndef RATIONAL_H
#define RATIONAL_H

#include <string>

class Rational {

public:

   explicit Rational( int = 0, int = 1 );

   void setN( int );
   void setD( int );

   int getN() const;
   int getD() const;

   void add( const Rational& );
   void subtract( const Rational& );
   void multiply( const Rational& );
   void divide( const Rational& );

   std::string toRationalString() const;
   double toDouble() const;

private:

   int numerator{};
   int denominator{ 1 };

   void reduce();
};

#endif