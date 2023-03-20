// Exercise 22.17: ex_22_17.cpp
// Searching for Substrings

#include <cstring>
#include <iostream>
using namespace std;

int main() {

   const char* str1{ "Test string" };
   const char* str2{ "st" };

   cout << "String: " << str1
      << "\nSubstring: " << str2 << endl;

   const char* searchPtr{ strstr( str1, str2 ) };

   if ( searchPtr ) {
      cout << "First remainder: " << searchPtr << endl;
      searchPtr = strstr( ++searchPtr, str2 );
      if ( searchPtr )
         cout << "Second remainder: " << searchPtr << endl;
   }

   return EXIT_SUCCESS;
}
