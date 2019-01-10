// Exercise 3.15: HeartRatesTest.cpp

#include <iostream>
#include <string>
#include "HeartRates.h"

using namespace std;

int main() {

   int bDay, bMonth, bYear;
   int cDay, cMonth, cYear;

   string fName, lName;

   cout << "Current date (dd mm yyyy): ";
   cin >> cDay >> cMonth >> cYear;

   cout << "\nPerson's Name (First Last): ";
   cin >> fName >> lName;

   cout << "Date of birth (dd mm yyyy): ";
   cin >> bDay >> bMonth >> bYear;

   HeartRates heartRates( fName, lName, bDay, bMonth, bYear );

   cout << "\nName: "
      << heartRates.getFirstName() << ' '
      << heartRates.getLastName()
      << "\nBirth date: "
      << heartRates.getBirthDay() << '.'
      << heartRates.getBirthMonth() << '.'
      << heartRates.getBirthYear()
      << "\nAge: "
      << heartRates.calculateAge( cDay, cMonth, cYear )
      << " years\nMaximum heart rate: "
      << heartRates.calculateMaximumHeartRate( cDay, cMonth, cYear )
      << " bpm\nTarget-heart-rate: ";
   heartRates.displayTargetHeartRate( cDay, cMonth, cYear );
   cout << " bpm" << endl;

   return 0;
}
