// Exercise 21.7: ex_21_07.cpp
// Simple Encryption

#include <iostream>
#include <string>
using namespace std;

int main() {

   const char ROT{ 13 }; // key
   string message;

   cout << "Message: ";
   getline( cin, message );

   // part a: encryption

   for ( auto& character : message )
      if ( isalpha( character ) ) {
         const char A{ isupper( character ) ? 'A' : 'a' };
         character = ( character + ROT - A ) % 26 + A;
      }

   cout << "\nEncrypted: " << message << endl;

   // part b: decryption

   for ( auto& character : message )
      if ( isalpha( character ) ) {
         const char Z{ isupper( character ) ? 'Z' : 'z' };
         character = ( character - ROT - Z ) % 26 + Z;
      }

   cout << "Decrypted: " << message << endl;

   return EXIT_SUCCESS;
}
