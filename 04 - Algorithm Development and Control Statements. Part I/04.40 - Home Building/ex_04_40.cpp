// Exercise 4.40: ex_04_40.cpp

#include <cmath>
#include <iostream>

using namespace std;

int main() {

   double height;

   cout << "Height and width, m (-1 to quit): ";
   cin >> height;

   while ( height != -1 ) {
      
      double width;
      cin >> width;

      double bricks{ height * width * 104 };
      double cement{ bricks * 0.00034 * 7 };

      cout << "230x115 mm bricks: " << ceil( bricks * 1.025 )
         << "\n50-kg cement bags: " << ceil( cement * 1.05 ) << endl;

      cout << "\nHeight and width, m (-1 to quit): ";
      cin >> height;
   }

   return 0;
}
