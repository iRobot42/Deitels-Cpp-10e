// Exercise 9.9: ex_09_09.cpp
// Student Class

#include <iostream>

#include "Student.h"

using namespace std;

int main() {

   Student s{ 'm', "Mr.", "John", "W.", "Smith",
      23, 1, 2002, 12345, "john@mail.box"};

   cout << s.getName() << '\n' << s.getDateOfBirth() << endl;

   return 0;
}
