// Exercise 9.9: Student.cpp
// Student class member-function definitions

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
   dateOfBirth.setDay( d );
   dateOfBirth.setMonth( m );
   dateOfBirth.setYear( y );
}
void Student::setEmail( string em ) { email = em; }
void Student::setName( string s, string f, string m, string l ) {
   name.setSalutation( s );
   name.setFirstName( f );
   name.setMiddleName( m );
   name.setLastName( l );
}
void Student::setRegNumber( unsigned int rn ) { registrationNumber = rn; }
void Student::setSex( char sx ) { sex = sx; }

const string Student::getDateOfBirth() const { return dateOfBirth.toString(); }
const string Student::getEmail() const { return email; }
const string Student::getName() const { return name.toString(); }
const unsigned int Student::getRegNumber() const { return registrationNumber; }
const char Student::getSex() const { return sex; }