// Exercise 10.11: Polynomial.h

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "Term.h"

class Polynomial {

   friend std::istream& operator>>( std::istream&, Polynomial& );
   friend std::ostream& operator<<( std::ostream&, const Polynomial& );

public:

   explicit Polynomial( const int = 1 /* monomial */ );
   Polynomial( const Polynomial& );
   ~Polynomial();

   Polynomial operator+( const Polynomial& ) const;
   Polynomial operator-( const Polynomial& ) const;
   Polynomial operator*( const Polynomial& ) const;
   const Polynomial& operator=( const Polynomial& );
   const Polynomial& operator+=( const Polynomial& );
   const Polynomial& operator-=( const Polynomial& );
   const Polynomial& operator*=( const Polynomial& );

   const int getSize() const;

private:

   int size;
   Term* ptr;

   void reduce();
};

#endif