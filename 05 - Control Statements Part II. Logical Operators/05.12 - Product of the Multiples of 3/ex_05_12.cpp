// Exercise 5.12: ex_05_12.cpp

#include <iostream>

int main() {

   double product{ 1.0 };

   for ( int i{ 3 }; i <= 50; i += 3 )
      product *= i;

   std::cout << product << std::endl;

   return 0;
}
