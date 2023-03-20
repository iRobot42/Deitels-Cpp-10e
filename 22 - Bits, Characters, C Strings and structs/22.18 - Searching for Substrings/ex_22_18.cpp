// Exercise 22.18: ex_22_18.cpp
// Searching for Substrings

#include <cstring>
#include <iostream>
using namespace std;

int subStr( const char*, const char* );

int main() {

   const char* str1{ "Do what you can, with what you have, where you are." };
   const char* str2{ "you" };

   cout << "String: " << str1
      << "\nSubstring: " << str2
      << "\nOccurences: " << subStr( str1, str2 ) << endl;

   return EXIT_SUCCESS;
}

int subStr( const char* str, const char* sub ) {

   int total{};

   while ( str = strstr( str, sub ) ) {
      total++;
      str++;
   }

   return total;
}
