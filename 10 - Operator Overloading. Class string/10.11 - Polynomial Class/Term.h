// Exercise 10.11: Term.h

#ifndef TERM_H
#define TERM_H

class Term {

   friend std::istream& operator>>( std::istream&, Term& );
   friend std::ostream& operator<<( std::ostream&, const Term& );

public:

   explicit Term( const int = 0, const int = 0);

   void setCoefficient( const int );
   void setExponent( const int );

   const int getCoefficient() const;
   const int getExponent() const;

private:

   int coefficient;
   int exponent;
};

#endif