// Exercise 9.8: Student.h
// Student class definition. Member functions defined in Student.cpp

#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {

public:

   Student( std::string, std::string, std::string, char,
      unsigned int, unsigned int, std::string );

   void setEmail( std::string );
   void setFirstName( std::string );
   void setLastName( std::string );
   void setMiddleName( std::string );
   void setRegNumber( unsigned int );
   void setSex( char );
   void setYearOfBirth( unsigned int );

   const std::string  getEmail() const;
   const std::string  getFirstName() const;
   const std::string  getLastName() const;
   const std::string  getMiddleName() const;
   const unsigned int getRegNumber() const;
   const char         getSex() const;
   const unsigned int getYearOfBirth() const;

private:

   std::string  email;
   std::string  firstName;
   std::string  lastName;
   std::string  middleName;
   unsigned int registrationNumber;
   char         sex;
   unsigned int yearOfBirth;
};

#endif