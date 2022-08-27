// Exercise 17.22: ex_17_22.cpp
// Catching Derived-Class Exceptions

#include <iostream>
#include <stdexcept>

using namespace std;

class RT1 : public runtime_error {
public: RT1() : runtime_error{ "1" } {};
};

class RT2 : public runtime_error {
public: RT2() : runtime_error{ "2" } {};
};

class RT3 : public runtime_error {
public: RT3() : runtime_error{ "3" } {};
};

int main() {

   for ( int ex{ 1 }; ex <= 3; ++ex ) {
      try {
         switch ( ex ) {
         case 1: throw RT1{};
         case 2: throw RT2{};
         case 3: throw RT3{};
         }
      }
      catch ( const runtime_error& INDEX ) {
         cerr << "RT" << INDEX.what() << endl;
      }
   }

   return EXIT_SUCCESS;
}
