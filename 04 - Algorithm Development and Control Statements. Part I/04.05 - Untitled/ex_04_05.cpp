// Exercise 4.5: ex_04_05.cpp

#include <iostream>

int main() {

   long var{ 10 }; // a
   long x{ 0 }; // b

   while ( x <= 10 ) {
      var -= x; // c
      x++;
      if ( var >= 0 )
         std::cout << var << std::endl; // d
   }

   return 0;
}
