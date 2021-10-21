// Exercise 9.14: HugeInteger.h
// Member functions defined in HugeInteger.cpp

#ifndef HUGEINTEGER_H
#define HUGEINTEGER_H

#include <array>

static const size_t SIZE{ 40 };

class HugeInteger {

public:

   HugeInteger();

   void input();
   std::string output() const;

   void add( const HugeInteger& );
   void subtract( const HugeInteger& );
   void multiply( const HugeInteger& );
   void divide( const HugeInteger& );
   void remainder( const HugeInteger& );

   bool isZero() const;
   bool isEqualTo( const HugeInteger& ) const;
   bool isNotEqualTo( const HugeInteger& ) const;
   bool isGreaterThan( const HugeInteger& ) const;
   bool isLessThan( const HugeInteger& ) const;
   bool isGreaterThanOrEqualTo( const HugeInteger& ) const;
   bool isLessThanOrEqualTo( const HugeInteger& ) const;

private:

   std::array< short, SIZE > number{}; // unsigned
};

#endif