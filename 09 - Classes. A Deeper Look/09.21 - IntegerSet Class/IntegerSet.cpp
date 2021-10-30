// Exercise 9.21: IntegerSet.cpp
// IntegerSet class member-function definitions

#include <sstream>

#include "IntegerSet.h"

using namespace std;

IntegerSet::IntegerSet() : a( vector< bool >( SIZE, false ) ) {}

IntegerSet::IntegerSet( const array< int, SIZE > A ) {
   a = vector< bool >( SIZE, false );
   for ( size_t i{}; i < SIZE; ++i )
      insertElement( A[ i ] );
}

void IntegerSet::insertElement( const int& k ) {
   if ( isValidNumber( k ) )
      a[ k ] = true;
   else throw ( "the element to be inserted is invalid" );
}

void IntegerSet::deleteElement( const int& m ) {
   if ( isValidNumber( m ) )
      a[ m ] = false;
   else throw ( "the element to be deleted is invalid" );
}

string IntegerSet::toString() const {

   ostringstream output;

   if ( isEmpty() ) output << "---";
   else for ( size_t i{}; i < SIZE; ++i )
      if ( a[ i ] ) output << i << ' ';

   return output.str();
}

IntegerSet IntegerSet::unionOfSets( const IntegerSet& IS ) const {

   IntegerSet Union;

   for ( size_t i{}; i < SIZE; ++i )
      if ( a[ i ] || IS.a[ i ] )
         Union.a[ i ] = true;

   return Union;
}

IntegerSet IntegerSet::intersectionOfSets( const IntegerSet& IS ) const {

   IntegerSet Intersection;

   for ( size_t i{}; i < SIZE; ++i )
      if ( a[ i ] && IS.a[ i ] )
         Intersection.a[ i ] = true;

   return Intersection;
}

bool IntegerSet::isEqualTo( const IntegerSet& IS ) const {
   return a == IS.a;
}

bool IntegerSet::isEmpty() const {
   for ( const auto& element : a )
      if ( element ) return false;
   return true;
}

bool IntegerSet::isValidNumber( const int& N ) const {
   return N >= 0 && N < SIZE;
}
