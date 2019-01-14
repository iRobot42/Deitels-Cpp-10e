// Exercise 6.49: ex_06_49.cpp

#include <iostream>

using namespace std;

inline int tripleByValue( int number ) { return number * 3; }
inline void tripleByReference( int& number ) { number *= 3; }

int main() {

   int count;
   int& countRef{ count };

   cout << "Number: ";
   cin >> count;

   cout << "Tripled by value: " << tripleByValue( count ) << endl;

   tripleByReference( countRef ); // modifies original value
   cout << "Tripled by reference: " << count << endl;

   return 0;
}
