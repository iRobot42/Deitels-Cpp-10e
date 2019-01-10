// Exercise 5.11: ex_05_11.cpp

#include <iostream>

using namespace std;

int main() {

   int number;
   int smallest;   

   cout << "Number of values: ";
   cin >> number;

   cout << "\nValue: ";
   cin >> smallest;
   
   while ( --number ) {

      int value;

      cout << "Value: ";
      cin >> value;

      if ( value < smallest )
         smallest = value;
   }

   cout << "\nSmallest is " << smallest << endl;

   return 0;
}
