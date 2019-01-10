// Exercise 2.27: ex_02_27.cpp

#include <iostream>

using namespace std;

int main() {

   char ch;

   cout << "Character: ";
   cin >> ch;

   cout << "Integer equivalent is " << static_cast< int >( ch ) << endl;

   return 0;
}
