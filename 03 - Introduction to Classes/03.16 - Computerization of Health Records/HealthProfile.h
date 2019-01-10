// Exercise 3.16: HealthProfile.h

#include <iostream>
#include <string>

class HealthProfile {

public:

   HealthProfile( std::string fn, std::string ln, std::string g,
      int bd, int bm, int by, double h, double w ) {
      setFirstName( fn );
      setLastName( ln );
      setGender( g );
      setBirthDay( bd );
      setBirthMonth( bm );
      setBirthYear( by );
      setHeight( h );
      setWeight( w );
   }

   void setFirstName( std::string fn ) {
      firstName = fn;
   }

   void setLastName( std::string ln ) {
      lastName = ln;
   }

   void setGender( std::string g ) {
      gender = g;
   }

   void setBirthDay( int bd ) {
      birthDay = bd;
   }

   void setBirthMonth( int bm ) {
      birthMonth = bm;
   }

   void setBirthYear( int by ) {
      birthYear = by;
   }

   void setHeight( double h ) {
      height = h;
   }

   void setWeight( double w ) {
      weight = w;
   }

   std::string getFirstName() const {
      return firstName;
   }

   std::string getLastName() const {
      return lastName;
   }

   std::string getGender() const {
      return gender;
   }

   int getBirthDay() const {
      return birthDay;
   }

   int getBirthMonth() const {
      return birthMonth;
   }

   int getBirthYear() const {
      return birthYear;
   }

   double getHeight() const {
      return height;
   }

   double getWeight() const {
      return weight;
   }

   int calculateAge( int cd, int cm, int cy ) {

      int age{ cy - birthYear };

      if ( cm < birthMonth )
         age = age - 1;

      if ( cm == birthMonth )
         if ( cd < birthDay )
            age = age - 1;

      return age;
   }

   int calculateMaximumHeartRate( int cd, int cm, int cy ) {
      return 220 - calculateAge( cd, cm, cy );
   }

   void displayTargetHeartRate( int cd, int cm, int cy ) {
      std::cout << calculateMaximumHeartRate( cd, cm, cy ) * 0.5 << " - "
         << calculateMaximumHeartRate( cd, cm, cy ) * 0.85;
   }

   double calculateBMI( double w, double h ) {
      return w * 703 / ( h * h );
   }

private:

   std::string firstName;
   std::string lastName;
   std::string gender;
   int birthDay;
   int birthMonth;
   int birthYear;
   double height;
   double weight;
};
