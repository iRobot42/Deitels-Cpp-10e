// Exercise 3.12: DateTest.cpp

#include <iostream>
#include "Date.h"

using namespace std;

int main() {

   Date date( 11, 8, 1983 );

   cout << "Initial date: ";
   date.displayDate();

   date.setMonth( 13 );

   cout << "Modified date: ";
   date.displayDate();

   return 0;
}
