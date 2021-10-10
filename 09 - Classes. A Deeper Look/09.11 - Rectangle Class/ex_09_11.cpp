// Exercise 9.11: ex_09_11.cpp
// Rectangle Class

#include <iostream>

#include "Rectangle.h"

using namespace std;

int main() {

   Rectangle r{ 10, 4.2 }; // test
   
   cout << "Perimeter is " << r.perimeter()
      << "\nArea is " << r.area() << endl;

   return 0;
}
