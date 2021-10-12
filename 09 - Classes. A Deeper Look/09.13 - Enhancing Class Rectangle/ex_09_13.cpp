// Exercise 9.13: ex_09_13.cpp
// Enhancing Class Rectangle

#include "Rectangle.h"

int main() {

   const float A[]{  2.2,  9.0 };
   const float B[]{ 17.4,  9.0 };
   const float C[]{  2.2, 18.9 };
   const float D[]{ 17.4, 18.9 };

   Rectangle r{ A, B, C, D, '-', 'x' };

   r.scale( 0.5 );
   r.move( 15.1, -6.5 );

   r.print();
   r.draw();

   return 0;
}
