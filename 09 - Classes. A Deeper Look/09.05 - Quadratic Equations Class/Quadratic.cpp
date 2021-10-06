// Exercise 9.5: Quadratic.cpp
// Quadratic class member-function definitions

#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

#include "Quadratic.h"

using namespace std;

Quadratic::Quadratic( double ca, double cb, double cc ) :
   a( ca ? ca : 1.0 ), b( cb ), c( cc ) {}

void Quadratic::setA( double number ) {
   if ( number ) a = number;
   else a = 1.0;
}

void Quadratic::setB( double number ) { b = number; }

void Quadratic::setC( double number ) { c = number; }

double Quadratic::getA() const { return a; }

double Quadratic::getB() const { return b; }

double Quadratic::getC() const { return c; }

void Quadratic::add( Quadratic q ) {
   setA( a + q.getA() );
   setB( b + q.getB() );
   setC( c + q.getC() );
}

void Quadratic::subtract( Quadratic q ) {
   setA( a - q.getA() );
   setB( b - q.getB() );
   setC( c - q.getC() );
}

void Quadratic::solve() const {
   
   const double D{ b * b - 4 * a * c }; // discriminant

   if ( D <= 0 ) cout << "No Real Roots";
   else cout << "x1=" << ( -b + sqrt( D ) ) / ( 2 * a )
      << ", x2=" << ( -b - sqrt( D ) ) / ( 2 * a );
}

std::string Quadratic::toString() const {
   ostringstream output;
   output << a << variable << "^2" << showpos << b << variable << c << "=0";
   return output.str();
}