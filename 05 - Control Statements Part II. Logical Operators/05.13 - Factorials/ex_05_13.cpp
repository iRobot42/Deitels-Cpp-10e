// Exercise 5.13: ex_05_13.cpp

#include <iostream>

int main() {

   long nFact{ 1 };

   for ( int n{ 1 }; n <= 20; ++n ) {
      nFact *= n;
      std::cout << n << "!\t" << nFact << std::endl;
   }

   return 0;
}
