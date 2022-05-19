// Exercise 12.11: Employee.cpp

#include <sstream>
#include "Employee.h"

using namespace std;

Employee::Employee( const string& first, const string& last, const string& ssn,
                    int month, int day, int year )
   : firstName( first ), lastName( last ), socialSecurityNumber( ssn ),
     birthDate( month, day, year ) {
}

void Employee::setFirstName( const string& first ) {
   firstName = first;
}

void Employee::setLastName( const string& last ) {
   lastName = last;
}

void Employee::setSocialSecurityNumber( const string& ssn ) {
   socialSecurityNumber = ssn;
}

string Employee::getFirstName() const {
   return firstName;
}

string Employee::getLastName() const {
   return lastName;
}

string Employee::getSocialSecurityNumber() const {
   return socialSecurityNumber;
}

Date Employee::getBirthDate() const {
   return birthDate;
}

string Employee::toString() const {
   return getFirstName() + " " + getLastName()
      + "\nsocial security number: " + getSocialSecurityNumber();
}