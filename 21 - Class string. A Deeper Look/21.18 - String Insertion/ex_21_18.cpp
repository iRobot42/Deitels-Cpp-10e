// Exercise 21.18: ex_21_18.cpp
// String Insertion

#include <iostream>
#include <string>
using namespace std;

int main() {

   string s{ "exact middle -->  <-- of the string" };
   s.insert( s.size() / 2, "******" );
   cout << s << endl;

   return EXIT_SUCCESS;
}
