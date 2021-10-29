// Exercise 9.20: ex_09_20.cpp
// VicobaAccount Class

#include <iostream>

#include "VicobaAccount.h"

using namespace std;

int main() {

   VicobaAccount VA;

   VA.setRate( 0.02 );
   VA.setAmount( 10'000.0 );
   VA.setDuration( 3 );

   VA.print();

   try {
      //VicobaAccount Test{ -0.1, -1 };
      //VA.setAmount( -0.1 );
      //VA.setDuration( -1 );
   }
   catch ( const char* ex ) {
      cerr << "\nException: " << ex << endl;
   }

   return 0;
}
