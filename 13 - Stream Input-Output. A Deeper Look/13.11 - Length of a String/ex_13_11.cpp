// Exercise 13.11: ex_13_11.cpp
// Length of a String

#include <iomanip>
#include <iostream>

using namespace std;

int main() {

   const int SIZE{ 80 };
   char str[ SIZE ]{};

   cout << "String: ";
   cin.get( str, SIZE );
   cout << setw( cin.gcount() * 2 ) << str;

   return 0;
}
