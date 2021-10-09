// Exercise 9.10: ex_09_10.cpp
// Returning Error Indicators from Class Student's Functions

#include <iostream>
#include <stdexcept>

#include "Student.h"

using namespace std;

int main() {

   try {
      Student s{ 'm', "Mr.", "John", "W.", "Smith",
         23, 1, 2002, 0, "john@mail.box"};
   }
   catch ( invalid_argument& e ) {
      cerr << "Exception: " << e.what() << endl;
   }

   return 0;
}
