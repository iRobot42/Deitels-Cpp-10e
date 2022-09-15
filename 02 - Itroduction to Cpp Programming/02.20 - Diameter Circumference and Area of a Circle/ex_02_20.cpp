// Exercise 2.20: ex_02_20.cpp
// Diameter, Circumference and Area of a Circle

#include <iostream>
using namespace std;

int main() {

   int radius;

   cout << "Integer radius of a circle: ";
   cin >> radius;

   cout << "Diameter is " << 2 * radius
      << "\nCircumference is " << 2 * 3.14159 * radius
      << "\nArea is " << 3.14159 * radius * radius << endl;

   return 0;
}
