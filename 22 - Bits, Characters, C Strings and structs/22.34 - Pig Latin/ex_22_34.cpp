// Exercise 22.34: ex_22_34.cpp
// Pig Latin

#include <cstring>
#include <iostream>
using namespace std;

inline void printLatinWord( const char* ptr ) {
   cout << ptr + 1 << *ptr << "ay ";
}

int main() {

   char str[]{ "today's pig is tomorrows bacon" };
   char* token;
   char* next{ str };

   while ( token = strtok_s( next, " ", &next ) )
      printLatinWord( token );
   cout << endl;

   return EXIT_SUCCESS;
}
