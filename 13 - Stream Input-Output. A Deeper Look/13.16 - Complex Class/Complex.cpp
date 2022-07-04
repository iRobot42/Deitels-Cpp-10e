// Exercise 13.16: Complex.cpp

#include <iostream>
#include "Complex.h"

using namespace std;

istream& operator>>( istream& in, Complex& c ) {

   in >> c.real;

   if ( cin.peek() == ' ' )
      cin.ignore();

   char sign;
   in >> sign;

   if ( sign != '+' && sign != '-' )
      cin.clear( ios::failbit );

   if ( cin.peek() == ' ' )
      cin.ignore();

   in >> c.imaginary;
   c.imaginary *= ( sign == '+' ? 1 : -1 );

   if ( cin.peek() != 'i' )
      cin.clear( ios::failbit );

   return in;
}

ostream& operator<<( ostream& out, const Complex& C ) {
   if ( cin.good() )
      out << C.real << showpos << C.imaginary << 'i' << endl << noshowpos;
   else
      out << "ERROR!" << endl;
   return out;
}

Complex::Complex() {
   real = imaginary = 0;
}