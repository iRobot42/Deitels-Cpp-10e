// Exercise 9.22: ex_09_22.cpp
// Time Class Modification

#include <iostream>
#include <stdexcept>

#include "Time.h"

using namespace std;

void displayTime( const string& message, const Time& time ) {
   cout << message << "\nUniversal time: " << time.toUniversalString()
      << "\nStandard time: " << time.toStandardString() << "\n\n";
}

int main() {

   Time t1;
   Time t2{ 2 };
   Time t3{ 21, 34 };
   Time t4{ 12, 25, 42 };

   cout << "Constructed with:\n\n";
   displayTime( "t1: all arguments defaulted", t1 );
   displayTime( "t2: hour specified; minute and second defaulted", t2 );
   displayTime( "t3: hour and minute specified; second defaulted", t3 );
   displayTime( "t4: hour, minute and second specified", t4 );

   try {
      Time t5{ 27, 74, 99 };
   }
   catch ( invalid_argument& e ) {
      cerr << "Exception while initializing t5: " << e.what() << endl;
   }

   return 0;
}
