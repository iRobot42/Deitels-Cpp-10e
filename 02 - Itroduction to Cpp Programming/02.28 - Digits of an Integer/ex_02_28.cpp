// Exercise 2.28: ex_02_28.cpp

#include <iostream>

using namespace std;

int main() {

   int number;

   cout << "Four-digit integer: ";
   cin >> number;

   cout << number % 10 << "  "
        << number % 100 / 10 << "  "
        << number % 1000 / 100 << "  "
        << number / 1000 << endl;

   return 0;
}
