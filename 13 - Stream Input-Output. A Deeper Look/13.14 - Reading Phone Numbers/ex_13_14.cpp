// Exercise 13.14: ex_13_14.cpp
// Reading Phone Numbers with an Overloaded Stream Extraction Operator

#include <iostream>
#include "PhoneNumber.h"

using namespace std;

int main() {

   PhoneNumber phone;

   cout << "Enter phone number in the form (555) 555-5555:" << endl;
   cin >> phone;

   cout << "The phone number entered was:\n" << phone << endl;

   return 0;
}
