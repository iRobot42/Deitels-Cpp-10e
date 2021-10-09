// Exercise 9.10: Name.cpp
// Name class member-function definitions

#include <sstream>
#include <string>

#include "Name.h"

using namespace std;

Name::Name() {};
Name::Name( string fn, string mn, string ln, string s ) {
   setFirstName( fn );
   setMiddleName( mn );
   setLastName( ln );
   setSalutation( s );
}

void Name::setFirstName( string fn ) { firstName = fn; }
void Name::setMiddleName( string mn ) { middleName = mn; }
void Name::setLastName( string ln ) { lastName = ln; }
void Name::setSalutation( string s ) { salutation = s; }

const string Name::getFirstName() const { return firstName; }
const string Name::getMiddleName() const { return middleName; }
const string Name::getLastName() const { return lastName; }
const string Name::getSalutation() const { return salutation; }

const string Name::toString() const {
   ostringstream person;
   person << getSalutation() << ' ' << getFirstName() << ' '
      << getMiddleName() << ' ' << getLastName();
   return person.str();
}