// Exercise 9.4: ex_09_04.cpp
// Enhancing Class Time

#include <ctime>
#include <iostream>

#include "Time.h"

using namespace std;

int main() {

   Time localTime{ time( 0 ) };

   cout << "Universal time: " << localTime.toUniversalString()
      << "\nStandard time: " << localTime.toStandardString() << endl;

   return 0;
}
