// Exercise 10.10: Quadratic.h
// Member functions defined in Quadratic.cpp

#ifndef QUADRATIC_H
#define QUADRATIC_H

class Quadratic {

   friend std::ostream& operator<<( std::ostream&, const Quadratic& );

public:

   explicit Quadratic( double = 1.0, double = 0.0, double = 0.0 );

   Quadratic operator+( const Quadratic& ) const;
   Quadratic operator-( const Quadratic& ) const;

   void setA( double );
   void setB( double );
   void setC( double );

   double getA() const;
   double getB() const;
   double getC() const;

   void solve() const;

private:

   char variable{ 'x' };

   double a{ 1.0 };
   double b{};
   double c{};
};

#endif