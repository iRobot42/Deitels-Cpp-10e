// Exercise 22.20: ex_22_20.cpp
// Searching for Characters

#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int countStr( const char*, const char* );

int main() {

   const char* filename{ "file.txt" };
   const char* str{ "you" };

   cout << "Filename: " << filename
      << "\nSubstring: " << str
      << "\nOccurences: " << countStr( filename, str ) << endl;

   return EXIT_SUCCESS;
}

int countStr( const char* fn, const char* sub ) {

   ifstream file{ fn, ios::in };

   if ( !file ) {
      cerr << "File could not be opened" << endl;
      exit( EXIT_FAILURE );
   }

   string s;
   char c;

   while ( file.get( c ) )
      s.push_back( c );

   file.close();

   int total{};
   const char* str{ &s[ 0 ] };

   while ( str = strstr( str, sub ) ) {
      total++;
      str++;
   }

   return total;
}
