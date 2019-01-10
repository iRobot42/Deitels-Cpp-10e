// Exercise 3.16: HealthProfileTest.cpp

#include <iostream>
#include <string>
#include "HealthProfile.h"

using namespace std;

int main() {

   int cDay, cMonth, cYear;
   int bDay, bMonth, bYear;

   string fName, lName, gender;

   double height, weight;

   cout << "Current date (dd mm yyyy): ";
   cin >> cDay >> cMonth >> cYear;

   cout << "\nPerson's Name (First Last): ";
   cin >> fName >> lName;

   cout << "Gender (Male/Female): ";
   cin >> gender;

   cout << "Date of birth (dd mm yyyy): ";
   cin >> bDay >> bMonth >> bYear;

   cout << "Height, in inches: ";
   cin >> height;

   cout << "Weight, in pounds: ";
   cin >> weight;

   HealthProfile healthProfile( fName, lName, gender, bDay, bMonth, bYear,
      height, weight );

   cout << "\nName: "
      << healthProfile.getFirstName() << ' '
      << healthProfile.getLastName()
      << "\nGender: "
      << healthProfile.getGender()
      << "\nBirth date: "
      << healthProfile.getBirthDay() << '.'
      << healthProfile.getBirthMonth() << '.'
      << healthProfile.getBirthYear()
      << "\nAge: "
      << healthProfile.calculateAge( cDay, cMonth, cYear )
      << " years\nHeight: "
      << healthProfile.getHeight()
      << " inches\nWeight: "
      << healthProfile.getWeight()
      << " pounds\nMaximum heart rate: "
      << healthProfile.calculateMaximumHeartRate( cDay, cMonth, cYear )
      << " bpm\nTarget-heart-rate: ";
   healthProfile.displayTargetHeartRate( cDay, cMonth, cYear );
   cout << " bpm\nBody Mass Index: "
      << healthProfile.calculateBMI( weight, height ) << endl;

   cout << "\nBMI VALUES"
        << "\nUnderweight: less than 18.5"
        << "\nNormal:      between 18.5 and 24.9"
        << "\nOverweight:  between 25 and 29.9"
        << "\nObese:       30 or greater" << endl;

   return 0;
}
