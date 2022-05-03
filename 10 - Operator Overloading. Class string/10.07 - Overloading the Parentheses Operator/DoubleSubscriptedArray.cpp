// Exercise 10.7: DoubleSubscriptedArray.cpp
// DoubleSubscriptedArray class member-function definitions

#include <iomanip>
#include <iostream>
#include <stdexcept>

#include "DoubleSubscriptedArray.h"

using namespace std;

istream& operator>>( istream& input, DoubleSubscriptedArray& a ) {
   for ( int i{}; i < a.rows * a.cols; ++i )
      input >> a.ptr[ i ];
   return input;
}

ostream& operator<<( ostream& output, const DoubleSubscriptedArray& a ) {
   output << right;
   for ( int r{}; r < a.rows; ++r ) {
      for ( int c{}; c < a.cols; ++c )
         output << setw( 4 ) << a.ptr[ r * a.cols + c ] << ' ';
      output << endl;
   }
   return output;
}

DoubleSubscriptedArray::DoubleSubscriptedArray( const int row, const int col ) :
   rows{ row > 0 ? row : throw invalid_argument{ "Incorrect rows number" } },
   cols{ col > 0 ? col : throw invalid_argument{ "incorrect cols number" } },
   ptr{ new int[ row * col ]{} }
{}

DoubleSubscriptedArray::DoubleSubscriptedArray( const DoubleSubscriptedArray&
   arrayToCopy ) : rows{ arrayToCopy.rows }, cols{ arrayToCopy.cols },
   ptr{ new int[ rows * cols ] } {

   for ( int i{}; i < rows * cols; ++i )
      ptr[ i ] = arrayToCopy.ptr[ i ];
}

DoubleSubscriptedArray::~DoubleSubscriptedArray() {
   delete[] ptr;
}

const DoubleSubscriptedArray& DoubleSubscriptedArray::operator=(
   const DoubleSubscriptedArray& right ) {

   if ( &right != this ) {
      
      if ( rows * cols != right.rows * right.cols ) {
         delete[] ptr;
         rows = right.rows;
         cols = right.cols;
         ptr = new int[ rows * cols ];
      }

      for ( int i{}; i < rows * cols; ++i )
         ptr[ i ] = right.ptr[ i ];
   }

   return *this;
}

bool DoubleSubscriptedArray::operator==( const DoubleSubscriptedArray& right )
   const {

   if ( rows * cols != right.rows * right.cols )
      return false;

   for ( int i{}; i < rows * cols; ++i )
      if ( ptr[ i ] != right.ptr[ i ] )
         return false;

   return true;
}

bool DoubleSubscriptedArray::operator!=( const DoubleSubscriptedArray& right )
   const {
   return !( *this == right );
}

int& DoubleSubscriptedArray::operator[]( int subscript ) {
   if ( subscript < 0 || subscript >= rows * cols )
      throw out_of_range( "Subscript out of range" );
   return ptr[ subscript ];
}

int DoubleSubscriptedArray::operator[]( int subscript ) const {
   if ( subscript < 0 || subscript >= rows * cols )
      throw out_of_range( "Subscript out of range" );
   return ptr[ subscript ];
}

int& DoubleSubscriptedArray::operator()( int row, int col ) {
   if ( row < 0 || row >= rows || col < 0 || col >= cols )
      throw out_of_range( "Subscript out of range" );
   return ptr[ row * cols + col ];
}

int DoubleSubscriptedArray::operator()( int row, int col ) const {
   if ( row < 0 || row >= rows || col < 0 || col >= cols )
      throw out_of_range( "Subscript out of range" );
   return ptr[ row * cols + col ];
}

unsigned DoubleSubscriptedArray::getSize() const {
   return rows * cols;
}