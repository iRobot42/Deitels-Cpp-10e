// Exercise 4.37: ex_04_37.cpp

#include <iostream>

using namespace std;

int main() {

// PART A - ENCRYPTING

   int dec{ 0 };

   while ( !dec ) {
      
      cout << "Four-digit integer: ";
      cin >> dec;

      if ( dec < 1000 )
         dec = 0;
      else if ( dec > 9999 )
         dec = 0;
   }

   int enc{ ( dec % 100 / 10 + 7 ) % 10 * 1000 +
            ( dec % 10 + 7 ) % 10 * 100 +
            ( dec / 1000 + 7 ) % 10 * 10 +
            ( dec % 1000 / 100 + 7 ) % 10 };

   cout << "Encrypted: " << enc << "\n\n";

// PART B - DECRYPTING

   enc = -1;

   while ( enc < 0 ) {

      cout << "Encrypted number: ";
      cin >> enc;

      if ( enc > 9999 )
         enc = -1;
   }

   dec = ( enc % 100 / 10 + 3 ) % 10 * 1000 +
         ( enc % 10 + 3 ) % 10 * 100 +
         ( enc / 1000 + 3 ) % 10 * 10 +
         ( enc % 1000 / 100 + 3 ) % 10;

   cout << "Decrypted: " << dec << endl;

   return 0;
}
