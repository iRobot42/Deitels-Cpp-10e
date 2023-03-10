// Exercise 21.22: ex_21_22.cpp
// Using the erase Functions with Iterator Arguments

#include <iostream>
#include <string>
using namespace std;

int main() {

   string s{ "i, Robot" };

   cout << s << endl;

   s.erase( s.cbegin() + 1, s.cend() - 5 );

   cout << s << endl;

   return EXIT_SUCCESS;
}
