// Exercise 9.8: Student.cpp
// Student class member-function definitions

#include <string>

#include "Student.h"

using namespace std;

Student::Student( string fn, string mn, string ln, char sx,
                  unsigned int yb, unsigned int rn, string em ) {
   
   setFirstName( fn );
   setMiddleName( mn );
   setLastName( ln );
   setSex( sx );
   setYearOfBirth( yb );
   setRegNumber( rn );
   setEmail( em );
}

// all setters assume correct values passed

void Student::setEmail( string em ) { email = em; }
void Student::setFirstName( string fn ) { firstName = fn; }
void Student::setLastName( string ln ) { lastName = ln; }
void Student::setMiddleName( string mn ) { middleName = mn; }
void Student::setRegNumber( unsigned int rn ) { registrationNumber = rn; }
void Student::setSex( char sx ) { sex = sx; }
void Student::setYearOfBirth( unsigned int yb ) { yearOfBirth = yb; }

const string Student::getEmail() const { return email; }
const string Student::getFirstName() const { return firstName; }
const string Student::getLastName() const { return lastName; }
const string Student::getMiddleName() const { return middleName; }
const unsigned int Student::getRegNumber() const { return registrationNumber; }
const char Student::getSex() const { return sex; }
const unsigned int Student::getYearOfBirth() const { return yearOfBirth; }