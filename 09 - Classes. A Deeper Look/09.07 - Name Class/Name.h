// Exercise 9.7: Name.h
// Name class definition. Member functions defined in Name.cpp

#ifndef NAME_H
#define NAME_H

#include <string>

class Name {

public:

   Name( std::string, std::string, std::string, std::string );

   void setFirstName( std::string );
   void setMiddleName( std::string );
   void setLastName( std::string );
   void setSalutation( std::string );

   const std::string getFirstName() const;
   const std::string getMiddleName() const;
   const std::string getLastName() const;
   const std::string getSalutation() const;

   const std::string toString() const;

private:

   std::string firstName;
   std::string middleName;
   std::string lastName;
   std::string salutation;
};

#endif