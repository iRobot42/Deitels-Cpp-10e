// Exercise 17.19: Quadratic.h

#ifndef QUADRATIC_H
#define QUADRATIC_H

#include <string>

class Quadratic {

public:

   explicit Quadratic( double = 1.0, double = 0.0, double = 0.0 );

   void setA( double );
   void setB( double );
   void setC( double );

   double getA() const;
   double getB() const;
   double getC() const;

   void add( Quadratic );
   void subtract( Quadratic );
   void solve() const;

   std::string toString() const;

private:

   char variable{ 'x' };

   double a{ 1.0 };
   double b{};
   double c{};
};

#endif