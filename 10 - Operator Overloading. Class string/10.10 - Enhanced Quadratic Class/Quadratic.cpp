// Exercise 10.10: Quadratic.cpp
// Quadratic class member-function definitions

#include <cmath>
#include <iostream>

#include "Quadratic.h"

using namespace std;

std::ostream& operator<<( ostream& output, const Quadratic& Q ) {
   output << noshowpos << Q.a << Q.variable << "^2" << showpos << Q.b
      << Q.variable << Q.c << "=0";
   return output;
}

Quadratic::Quadratic( double ca, double cb, double cc ) :
   a( ca ? ca : 1.0 ), b( cb ), c( cc )
{}

Quadratic Quadratic::operator+( const Quadratic& Q ) const {
   return Quadratic{ a + Q.a, b + Q.b, c + Q.c };
}

Quadratic Quadratic::operator-( const Quadratic& Q ) const {
   return Quadratic{ a - Q.a, b - Q.b, c - Q.c };
}

void Quadratic::setA( double number ) {
   a = number ? number : 1.0;
}

void Quadratic::setB( double number ) { b = number; }

void Quadratic::setC( double number ) { c = number; }

double Quadratic::getA() const { return a; }

double Quadratic::getB() const { return b; }

double Quadratic::getC() const { return c; }

void Quadratic::solve() const {

   const double D{ b * b - 4 * a * c }; // discriminant

   cout << noshowpos;

   if ( D <= 0 ) cout << "No Real Roots";
   else cout << "x1=" << ( -b + sqrt( D ) ) / ( 2 * a )
      << ", x2=" << ( -b - sqrt( D ) ) / ( 2 * a );
}
