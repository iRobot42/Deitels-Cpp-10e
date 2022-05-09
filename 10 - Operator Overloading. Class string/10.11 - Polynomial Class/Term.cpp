// Exercise 10.11: Term.cpp

#include <iostream>
#include "Term.h"

using namespace std;

istream& operator>>( istream& input, Term& T ) {
   input >> T.coefficient >> T.exponent;
   return input;
}

ostream& operator<<( ostream& output, const Term& T ) {

   if ( T.coefficient ) {

      if ( abs( T.coefficient ) == 1 && T.exponent )
         output << ( T.coefficient < 0 ? '-' : '+' );
      else
         output << showpos << T.coefficient << noshowpos;

      if ( T.exponent ) {
         output << 'x';
         if ( T.exponent != 1 )
            output << '^' << T.exponent;
      }
   }

   return output;
}

Term::Term( const int C, const int E ) {
   setCoefficient( C );
   setExponent( E );
}

void Term::setCoefficient( const int C ) {
   coefficient = C;
}

void Term::setExponent( const int E ) {
   exponent = E;
}

const int Term::getCoefficient() const {
   return coefficient;
}

const int Term::getExponent() const {
   return exponent;
}