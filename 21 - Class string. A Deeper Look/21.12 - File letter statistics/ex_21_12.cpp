// Exercise 21.12: ex_21_12.cpp
// File letter statistics

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {

   string filename;
   cout << "Filename: ";
   cin >> filename;

   ifstream file{ filename };
   if ( !file ) {
      cerr << "File could not be opened" << endl;
      exit( EXIT_FAILURE );
   }

   string sentence;
   int count[ 26 ]{};

   while ( getline( file, sentence ) )
      for ( const auto& CHARACTER : sentence )
         if ( isalpha( CHARACTER ) )
            count[ tolower( CHARACTER ) - 'a' ]++;

   file.close();

   for ( int i{}; i < 26; ++i )
      cout << char( 'a' + i ) << ": " << count[ i ] << endl;

   return EXIT_SUCCESS;
}
