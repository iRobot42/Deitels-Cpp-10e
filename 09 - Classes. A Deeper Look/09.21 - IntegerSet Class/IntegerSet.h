// Exercise 9.21: IntegerSet.h
// Member functions defined in IntegerSet.cpp

#ifndef INTEGERSET_H
#define INTEGERSET_H

#include <array>
#include <string>
#include <vector>

static const size_t SIZE{ 101 };

class IntegerSet {

public:

   IntegerSet(); // empty set
   explicit IntegerSet( const std::array< int, SIZE > );

   void insertElement( const int& );
   void deleteElement( const int& );

   std::string toString() const;

   IntegerSet unionOfSets( const IntegerSet& ) const;
   IntegerSet intersectionOfSets( const IntegerSet& ) const;
   bool isEqualTo( const IntegerSet& ) const;

private:

   std::vector< bool > a; // set

   bool isEmpty() const;
   bool isValidNumber( const int& ) const;
};

#endif
