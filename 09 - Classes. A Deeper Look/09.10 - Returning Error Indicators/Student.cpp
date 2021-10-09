// Exercise 9.10: Student.cpp
// Student class member-function definitions

#include <stdexcept>
#include <string>

#include "Student.h"

using namespace std;

Student::Student( char sx, string sl, string fn, string mn, string ln,
                  unsigned int bd, unsigned int bm, unsigned int by,
                  unsigned int rn, string em ) {

   setSex( sx );
   setName( sl, fn, mn, ln );
   setDateOfBirth( bd, bm, by );
   setRegNumber( rn );
   setEmail( em );
}

void Student::setDateOfBirth( unsigned int d, unsigned int m, unsigned int y ) {
   
   if ( d < 1 || d > 31 || m < 1 || m > 12 ) // simple check
      throw invalid_argument( "day must be 1-31, month must be 1-12" );
   else {
      dateOfBirth.setDay( d );
      dateOfBirth.setMonth( m );
      dateOfBirth.setYear( y );
   }
}

void Student::setEmail( string em ) { email = em; }

void Student::setName( string s, string f, string m, string l ) {

   if ( f == "" || m == "" || l == "" )
      throw invalid_argument( "empty name" );
   else {
      name.setSalutation( s );
      name.setFirstName( f );
      name.setMiddleName( m );
      name.setLastName( l );
   }
}

void Student::setRegNumber( unsigned int rn ) {

   if ( !rn ) throw invalid_argument( "incorrect registration number" );
   else registrationNumber = rn;
}

void Student::setSex( char sx ) {

   if ( sx != 'f' && sx != 'm' ) throw invalid_argument( "incorrect gender" );
   else sex = sx;
}

const string Student::getDateOfBirth() const { return dateOfBirth.toString(); }
const string Student::getEmail() const { return email; }
const string Student::getName() const { return name.toString(); }
const unsigned int Student::getRegNumber() const { return registrationNumber; }
const char Student::getSex() const { return sex; }