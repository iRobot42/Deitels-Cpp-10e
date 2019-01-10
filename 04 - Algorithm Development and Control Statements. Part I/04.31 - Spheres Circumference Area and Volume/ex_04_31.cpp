// Exercise 4.31: ex_04_31.cpp

#include <iostream>

using namespace std;

int main() {

   double r;

   cout << "Radius of a sphere: ";
   cin >> r;

   cout << "\nCircumference is " << 2 * 3.14159 * r
      << "\nSurface area is " << 4 * 3.14159 * r * r
      << "\nVolume is " << 3.14159 * 4 / 3 * r * r * r << endl;

   return 0;
}
