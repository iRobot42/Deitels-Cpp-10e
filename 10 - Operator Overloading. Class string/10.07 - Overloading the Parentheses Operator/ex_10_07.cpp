// Exercise 10.7: ex_10_07.cpp
// Overloading the Parentheses Operator

#include <iostream>
#include <stdexcept>

#include "DoubleSubscriptedArray.h"

using namespace std;

int main() {

   DoubleSubscriptedArray integers1{ 3, 5 };
   DoubleSubscriptedArray integers2;

   cout << "Size of array integers1 is " << integers1.getSize()
      << "\nArray after initialization:\n" << integers1;

   cout << "\nSize of array integers2 is " << integers2.getSize()
      << "\nArray after initialization:\n" << integers2;

   cout << "\nEnter " << integers1.getSize() + integers2.getSize()
      << " integers:" << endl;
   cin >> integers1 >> integers2;

   cout << "\nAfter input, the arrays contain:\n"
      << "integers1:\n" << integers1 << "integers2:\n" << integers2;

   cout << "\nEvaluating: integers1 != integers2" << endl;

   if ( integers1 != integers2 )
      cout << "integers1 and integers2 are not equal" << endl;

   DoubleSubscriptedArray integers3{ integers1 };

   cout << "\nSize of array integers3 is " << integers3.getSize()
      << "\nArray after initialization:\n" << integers3;

   cout << "\nAssigning integers2 to integers1:" << endl;
   integers1 = integers2;

   cout << "integers1:\n" << integers1 << "integers2:\n" << integers2;

   cout << "\nEvaluating: integers1 == integers2" << endl;

   if ( integers1 == integers2 )
      cout << "integers1 and integers2 are equal" << endl;

   cout << "\nintegers3[ 5 ] is " << integers3[ 5 ];

   cout << "\n\nAssigning 1000 to integers3[ 5 ]" << endl;
   integers3[ 5 ] = 1000;
   cout << "integers3:\n" << integers3;

   try {
      cout << "\nAttempt to assign 1000 to integers3[ 15 ]" << endl;
      integers3[ 15 ] = 1000;
   }
   catch ( out_of_range& ex ) {
      cout << "An exception occured: " << ex.what() << endl;
   }

   cout << "\nintegers3( 1, 3 ) is " << integers3( 1, 3 ) << endl; // rvalue
   
   cout << "\nAssigning 42 to integers3( 2, 4 )";
   integers3( 2, 4 ) = 42; // lvalue

   cout << "\nintegers3:\n" << integers3;

   return 0;
}
