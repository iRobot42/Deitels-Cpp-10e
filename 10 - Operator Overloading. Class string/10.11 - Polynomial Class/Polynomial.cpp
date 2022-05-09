// Exercise 10.11: Polynomial.cpp

#include <iostream>
#include "Polynomial.h"

using namespace std;

istream& operator>>( istream& input, Polynomial& P ) {
   for ( int i{}; i < P.size; ++i )
      cin >> P.ptr[ i ];
   P.reduce();
   return input;
}

ostream& operator<<( ostream& output, const Polynomial& P ) {
   for ( int i{}; i < P.size; ++i )
      output << P.ptr[ i ];
   return output;
}

Polynomial::Polynomial( const int S )
   : size{ S > 0 ? S : throw invalid_argument( "Incorrect size" ) },
     ptr{ new Term[ size ] } {
}

Polynomial::Polynomial( const Polynomial& P )
   : size{ P.size }, ptr{ new Term[ size ] } {
   for ( int i{}; i < size; ++i )
      ptr[ i ] = P.ptr[ i ];
}

Polynomial::~Polynomial() {
   delete[] ptr;
}

Polynomial Polynomial::operator+( const Polynomial& P ) const {

   Polynomial temp{ size + P.size };

   for ( int i{}; i < size; ++i )
      temp.ptr[ i ] = ptr[ i ];

   for ( int i{ size }; i < temp.size; ++i )
      temp.ptr[ i ] = P.ptr[ i - size ];

   temp.reduce();
   return temp;
}

Polynomial Polynomial::operator-( const Polynomial& P ) const {

   Polynomial temp{ size + P.size };

   for ( int i{}; i < size; ++i )
      temp.ptr[ i ] = ptr[ i ];

   for ( int i{ size }; i < temp.size; ++i ) {
      temp.ptr[ i ] = P.ptr[ i - size ];
      temp.ptr[ i ].setCoefficient( -temp.ptr[ i ].getCoefficient() );
   }

   temp.reduce();
   return temp;
}

Polynomial Polynomial::operator*( const Polynomial& P ) const {

   Polynomial temp{ size * P.size };

   for ( int i{}, t{}; i < size; ++i )
      for ( int j{}; j < P.size; ++j ) {
         temp.ptr[ t ].setCoefficient( ptr[ i ].getCoefficient() *
                                       P.ptr[ j ].getCoefficient() );
         temp.ptr[ t++ ].setExponent( ptr[ i ].getExponent() +
                                      P.ptr[ j ].getExponent() );
      }

   temp.reduce();
   return temp;
}

const Polynomial& Polynomial::operator=( const Polynomial& P ) {

   if ( &P != this ) {

      if ( size != P.size ) {
         delete[] ptr;
         size = P.size;
         ptr = new Term[ size ];
      }

      for ( int i{}; i < size; ++i )
         ptr[ i ] = P.ptr[ i ];
   }

   reduce();
   return *this;
}

const Polynomial& Polynomial::operator+=( const Polynomial& P ) {
   *this = *this + P;
   return *this;
}

const Polynomial& Polynomial::operator-=( const Polynomial& P ) {
   *this = *this - P;
   return *this;
}

const Polynomial& Polynomial::operator*=( const Polynomial& P ) {
   *this = *this * P;
   return *this;
}

const int Polynomial::getSize() const {
   return size;
}

void Polynomial::reduce() {

   int newSize{};

   for ( int i{}; i < size; ++i )
      if ( ptr[ i ].getCoefficient() ) {

         newSize++;
         for ( int j{ i + 1 }; j < size; ++j )
            if ( ptr[ j ].getCoefficient()
                 && ptr[ i ].getExponent() == ptr[ j ].getExponent() ) {

               ptr[ i ].setCoefficient( ptr[ i ].getCoefficient() +
                                        ptr[ j ].getCoefficient() );
               ptr[ j ].setCoefficient( 0 );
            }
      }

   if ( newSize && newSize < size ) {

      Polynomial reduced{ newSize };

      for ( int i{}, j{}; i < size; ++i )
         if ( ptr[ i ].getCoefficient() )
            reduced.ptr[ j++ ] = ptr[ i ];

      *this = reduced;
   }
   else if ( !newSize && size > 1 ) // all 0s
      *this = Polynomial{};
}