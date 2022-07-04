// Exercise 13.16: Complex.h

#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex {

   friend std::istream& operator>>( std::istream&, Complex& );
   friend std::ostream& operator<<( std::ostream&, const Complex& );

public:

   explicit Complex();

private:

   int real;
   int imaginary;
};

#endif