// Exercise 9.12: ex_09_12.cpp
// Enhancing Class Rectangle

#include "Rectangle.h"

int main() {

   const float A[]{  4.2, 1.0 };
   const float B[]{ 17.4, 1.0 };
   const float C[]{  4.2, 8.8 };
   const float D[]{ 17.4, 8.8 };

   Rectangle r{ A, B, C, D };

   r.print();

   return 0;
}
