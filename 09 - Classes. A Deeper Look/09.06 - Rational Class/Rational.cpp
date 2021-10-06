// Exercise 9.6: Rational.cpp
// Rational class member-function definitions

#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

#include "Rational.h"

using namespace std;

Rational::Rational( int n, int d ) {
   setN( n );
   setD( d );
   reduce();
}

void Rational::setN( int n ) { numerator = n; }

void Rational::setD( int d ) {
   if ( !d ) d = 1;
   if ( d < 0 ) setN( -getN() );
   denominator = abs( d );
}

int Rational::getN() const { return numerator; }

int Rational::getD() const { return denominator; }

void Rational::add( const Rational& RRef ) {
   setN( getN() * RRef.getD() + getD() * RRef.getN() ); // !lcm
   setD( getD() * RRef.getD() );
   reduce();
}

void Rational::subtract( const Rational& RRef ) {
   setN( getN() * RRef.getD() - getD() * RRef.getN() );
   setD( getD() * RRef.getD() );
   reduce();
}

void Rational::multiply( const Rational& RRef ) {
   setN( getN() * RRef.getN() );
   setD( getD() * RRef.getD() );
   reduce();
}

void Rational::divide( const Rational& RRef ) {
   if ( !RRef.getN() ) cout << "Error: attempt to divide by zero!" << endl;
   else {
      setN( getN() * RRef.getD() );
      setD( getD() * RRef.getN() );
      reduce();
   }
}

string Rational::toRationalString() const {
   ostringstream output;
   if ( !getN() || getD() == 1 ) output << getN();
   else output << getN() << '/' << getD();
   return output.str();
}

double Rational::toDouble() const {
   return static_cast< double >( numerator ) / denominator;
}

void Rational::reduce() {
   if ( !numerator ) return;
   int gcd{ abs( numerator ) };
   int n{ denominator }; // already positive
   while ( gcd != n ) gcd > n ? gcd -= n : n -= gcd;
   setN( numerator / gcd );
   setD( denominator / gcd );
}