// Exercise 21.10: ex_21_10.cpp
// String Concatenation

#include <iostream>
#include <string>
using namespace std;

int main() {

   string first, last;

   cout << "First name: ";
   cin >> first;
   cout << "Last name: ";
   cin >> last;

   string name{ first + ' ' + last }; // 1
   cout << "Technique #1: " << name << endl;

   name.clear();
   name.append( first + ' ' + last ); // 2
   cout << "Technique #2: " << name << endl;

   return EXIT_SUCCESS;
}
