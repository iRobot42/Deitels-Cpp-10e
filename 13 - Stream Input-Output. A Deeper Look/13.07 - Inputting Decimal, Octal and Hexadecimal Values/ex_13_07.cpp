// Exercise 13.7: ex_13_07.cpp
// Inputting Decimal, Octal and Hexadecial Values

#include <iostream>

using namespace std;

inline void showFormats( const int VALUE ) {
   cout << "Dec " << dec << VALUE
      << "\nOct " << oct << VALUE
      << "\nHex " << hex << VALUE << endl;
}

int main() {

   int value{};

   cout << showbase << "Decimal format: ";
   cin >> dec >> value;
   showFormats( value );

   cout << "\nOctal format: ";
   cin >> oct >> value;
   showFormats( value );

   cout << "\nHexadecimal format: ";
   cin >> hex >> value;
   showFormats( value );

   return 0;
}
