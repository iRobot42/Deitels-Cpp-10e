// Exercise 9.7: ex_09_07.cpp
// Name Class

#include <iostream>

#include "Name.h"

using namespace std;

int main() {

   Name p{ "John", "W.", "Smith", "Mr." };

   cout << p.toString() << endl;

   return 0;
}
