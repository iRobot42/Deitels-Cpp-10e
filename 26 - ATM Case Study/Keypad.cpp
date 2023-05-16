// Keypad.cpp

#include <iostream>
#include "Keypad.h"

using namespace std;

int Keypad::getInput() const {
   int input;
   cin >> input;
   return input;
}