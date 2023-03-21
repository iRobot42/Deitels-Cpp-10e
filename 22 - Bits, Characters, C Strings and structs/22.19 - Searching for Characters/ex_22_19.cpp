// Exercise 22.19: ex_22_19.cpp
// Searching for Characters

#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int countChr( const char*, const char );

int main() {

   const char* FILENAME{ "file.txt" };
   const char CHAR{ 'i' };

   cout << "Filename: " << FILENAME
      << "\nCharacter: " << CHAR
      << "\nOccurences: " << countChr( FILENAME, CHAR ) << endl;

   return EXIT_SUCCESS;
}

int countChr( const char* filename, const char CHR ) {

   ifstream file{ filename, ios::in };

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

   while ( str = strchr( str, CHR ) ) {
      total++;
      str++;
   }

   return total;
}
