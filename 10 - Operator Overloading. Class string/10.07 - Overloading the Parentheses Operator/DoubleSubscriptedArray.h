// Exercise 10.7: DoubleSubscriptedArray.h
// Member functions defined in DoubleSubscriptedArray.cpp

#ifndef DOUBLESUBSCRIPTEDARRAY_H
#define DOUBLESUBSCRIPTEDARRAY_H

#include <iostream>

class DoubleSubscriptedArray {

   friend std::istream& operator>>( std::istream&, DoubleSubscriptedArray& );
   friend std::ostream& operator<<( std::ostream&, const DoubleSubscriptedArray& );

public:

   explicit DoubleSubscriptedArray( const int = 1, const int = 1 );
   DoubleSubscriptedArray( const DoubleSubscriptedArray& );
   ~DoubleSubscriptedArray();

   const DoubleSubscriptedArray& operator=( const DoubleSubscriptedArray& );
   bool operator==( const DoubleSubscriptedArray& ) const;
   bool operator!=( const DoubleSubscriptedArray& ) const;
   int& operator[]( int );
   int operator[]( int ) const;
   int& operator()( int, int );
   int operator()( int, int ) const;

   unsigned getSize() const;

private:

   int rows;
   int cols;
   int* ptr;
};

#endif
