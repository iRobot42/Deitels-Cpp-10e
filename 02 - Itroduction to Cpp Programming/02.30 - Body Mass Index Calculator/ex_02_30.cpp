// Exercise 2.30: ex_02_30.cpp

#include <iostream>

using namespace std;

int main() {

   double height;
   double weight;

   cout << "Weight (kg): ";
   cin >> weight;
   cout << "Height (m): ";
   cin >> height;

   cout << "\nBody Mass Index is "
        << weight / ( height * height ) << endl;

   cout << "\nBMI VALUES"
        << "\nUnderweight: less than 18.5"
        << "\nNormal:      between 18.5 and 24.9"
        << "\nOverweight:  between 25 and 29.9"
        << "\nObese:       30 or greater" << endl;

   return 0;
}
