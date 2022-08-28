// Exercise 18.4: Array.h

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <stdexcept>

template< typename T >
class Array {

   friend std::istream& operator>>( std::istream& input, Array& a ) {
      for ( size_t i{}; i < a.size; ++i )
         input >> a.ptr[ i ];
      return input;
   }

   friend std::ostream& operator<<( std::ostream& output, const Array& A ) {
      for ( size_t i{}; i < A.size; ++i )
         output << A.ptr[ i ] << ' ';
      return output;
   }

public:

   Array( const int SIZE = 10 ) :
      size{ SIZE > 0 ? static_cast< size_t >( SIZE ) :
         throw std::invalid_argument{ "array size must be greater than 0" } },
      ptr{ new T[ size ]{} } {
   }

   Array( const Array& A ) : size{ A.size }, ptr{ new T[ size ] } {
      for ( size_t i{}; i < size; ++i )
         ptr[ i ] = A.ptr[ i ];
   }

   ~Array() {
      std::cout << '~';
      delete[] ptr;
   }

   size_t getSize() const {
      return size;
   }

   const Array& operator=( const Array& RIGHT ) {
      if ( &RIGHT != this ) {
         if ( size != RIGHT.size ) {
            delete[] ptr;
            size = RIGHT.size;
            ptr = new T[ size ];
         }
         for ( size_t i{}; i < size; ++i )
            ptr[ i ] = RIGHT.ptr[ i ];
      }
      return *this;
   }

   bool operator==( const Array& RIGHT ) const {
      if ( size != RIGHT.size )
         return false;
      for ( size_t i{}; i < size; ++i )
         if ( ptr[ i ] != RIGHT.ptr[ i ] )
            return false;
      return true;
   }

   bool operator!=( const Array& RIGHT ) const {
      return !( *this == RIGHT );
   }

   T& operator[]( const int SUBSCRIPT ) {
      if ( SUBSCRIPT < 0 || SUBSCRIPT >= size )
         throw std::out_of_range{ "subscript out of range" };
      return ptr[ SUBSCRIPT ];
   }

   T operator[]( const int SUBSCRIPT ) const {
      if ( SUBSCRIPT < 0 || SUBSCRIPT >= size )
         throw std::out_of_range{ "subscript out of range" };
      return ptr[ SUBSCRIPT ];
   }

private:

   size_t size;
   T* ptr;
};

#endif