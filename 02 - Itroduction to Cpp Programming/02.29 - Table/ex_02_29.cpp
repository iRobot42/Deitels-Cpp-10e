// Exercise 2.29: ex_02_29.cpp

#include <iostream>

using namespace std;

int main() {

   cout << "Face length\tSurface area\tVolume\n"
      << "of cube (cm)\tof cube (cm^2)\tof cube (cm^3)\n\n"
      << 0 << "\t\t" << 0 * 0 * 6 << "\t\t" << 0 * 0 * 0 << '\n'
      << 1 << "\t\t" << 1 * 1 * 6 << "\t\t" << 1 * 1 * 1 << '\n'
      << 2 << "\t\t" << 2 * 2 * 6 << "\t\t" << 2 * 2 * 2 << '\n'
      << 3 << "\t\t" << 3 * 3 * 6 << "\t\t" << 3 * 3 * 3 << '\n'
      << 4 << "\t\t" << 4 * 4 * 6 << "\t\t" << 4 * 4 * 4 << endl;

   return 0;
}
