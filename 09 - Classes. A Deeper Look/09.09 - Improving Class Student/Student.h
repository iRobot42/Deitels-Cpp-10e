// Exercise 9.9: Student.h
// Member functions defined in Student.cpp

#ifndef STUDENT_H
#define STUDENT_H

#include <string>

#include "Date.h"
#include "Name.h"

class Student {

public:

   Student( char, std::string, std::string, std::string, std::string,
            unsigned int, unsigned int, unsigned int,
            unsigned int, std::string );

   void setDateOfBirth( unsigned int, unsigned int, unsigned int );
   void setEmail( std::string );
   void setName( std::string, std::string, std::string, std::string );
   void setRegNumber( unsigned int );
   void setSex( char );
   
   const std::string  getDateOfBirth() const;
   const std::string  getEmail() const;
   const std::string  getName() const;
   const unsigned int getRegNumber() const;
   const char         getSex() const;
   
private:

   Date         dateOfBirth;
   std::string  email;
   Name         name;
   unsigned int registrationNumber;
   char         sex;
};

#endif