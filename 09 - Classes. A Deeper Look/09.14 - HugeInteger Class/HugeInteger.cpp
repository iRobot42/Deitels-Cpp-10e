// Exercise 9.14: HugeInteger.cpp
// HugeInteger class member-function definitions

#include <iostream>
#include <stdexcept>
#include <string>

#include "HugeInteger.h"

using namespace std;

HugeInteger::HugeInteger() {}

void HugeInteger::input() {

   number.fill( 0 );

   string s;

   cout << "Number: ";
   cin >> s;

   if ( s.size() > SIZE ) throw( "number is too large" );

   for ( size_t i{ SIZE - s.size() }, j{}; i < SIZE; ++i, ++j )
      number[ i ] = isdigit( s[ j ] ) ? s[ j ] - '0' : 0;
}

string HugeInteger::output() const {

   size_t i{};
   string output{};

   while ( i < SIZE - 1 && !number[ i ] ) i++; // skip redundant 0s
   while ( i < SIZE ) output.push_back( '0' + number[ i++ ] );

   return output;
}

void HugeInteger::add( const HugeInteger& HUGE ) {

   bool carry{ false };

   for ( int i{ SIZE - 1 }; i >= 0; --i ) {

      const short N{ number[ i ] + HUGE.number[ i ] + carry };

      number[ i ] = N % 10;
      carry = N / 10;
   }

   if ( carry ) throw( "no place to store the sum" );
}

void HugeInteger::subtract( const HugeInteger& HUGE ) {

   if ( this->isLessThan( HUGE ) ) throw( "the result cannot be negative" );
   else for ( int i{ SIZE - 1 }; i >= 0; --i ) {

      if ( number[ i ] < HUGE.number[ i ] ) {
         number[ i ] += 10;
         number[ i - 1 ]--;
      }

      number[ i ] -= HUGE.number[ i ];
   }
}

void HugeInteger::multiply( const HugeInteger& HUGE ) {

   HugeInteger result;

   for ( int i2{ SIZE - 1 }; i2 >= 0; --i2 ) {

      HugeInteger temp;
      short carry{};

      for ( int i1{ SIZE - 1 }; i1 >= 0; --i1 ) {

         const short N{ number[ i1 ] * HUGE.number[ i2 ] + carry };

         temp.number[ i1 ] = N % 10;
         carry = N / 10;
      }

      if ( carry ) throw( "no place to store the product" );

      size_t shift{ SIZE - i2 };

      while ( --shift ) {
         if ( temp.number.front() ) throw( "no room to shift" );
         for ( size_t i{}; i < SIZE - 1; ++i )
            temp.number[ i ] = temp.number[ i + 1 ];
         temp.number.back() = 0;
      }

      result.add( temp );
   }

   number = result.number;
}

void HugeInteger::divide( const HugeInteger& HUGE ) {

   if ( HUGE.isZero() ) throw( "attempt to divide by zero" );

   HugeInteger temp;
   array< short, SIZE > result{};

   for ( size_t i{}; i < SIZE; ++i ) {

      temp.number.back() = number[ i ];

      short n{};

      while ( temp.isGreaterThanOrEqualTo( HUGE ) ) {
         temp.subtract( HUGE );
         n++;
      }

      result[ i ] = n;

      for ( int j{}; j < SIZE - 1; ++j )
         temp.number[ j ] = temp.number[ j + 1 ];
   }

   number = result;
}

void HugeInteger::remainder( const HugeInteger& HUGE ) {

   HugeInteger temp;

   temp.number = number;
   temp.divide( HUGE );
   temp.multiply( HUGE );
   this->subtract( temp );
}

bool HugeInteger::isZero() const {

   for ( const auto& element : number )
      if ( element ) return false;

   return true;
}

bool HugeInteger::isEqualTo( const HugeInteger& HUGE ) const {
   return number == HUGE.number;
}

bool HugeInteger::isNotEqualTo( const HugeInteger& HUGE ) const {
   return number != HUGE.number;
}

bool HugeInteger::isGreaterThan( const HugeInteger& HUGE ) const {
   return number > HUGE.number;
}

bool HugeInteger::isLessThan( const HugeInteger& HUGE ) const {
   return number < HUGE.number;
}

bool HugeInteger::isGreaterThanOrEqualTo( const HugeInteger& HUGE ) const {
   return number >= HUGE.number;
}

bool HugeInteger::isLessThanOrEqualTo( const HugeInteger& HUGE ) const {
   return number <= HUGE.number;
}