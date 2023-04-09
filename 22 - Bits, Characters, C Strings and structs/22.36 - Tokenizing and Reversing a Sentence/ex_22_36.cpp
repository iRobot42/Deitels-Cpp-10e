// Exercise 22.36: ex_22_36.cpp
// Tokenizing and Reversing a Sentence

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

vector< char* > tokenize( const string&, const string& );

int main() {

   string s{ "Square box, round pizza, triangle slices." }, d{ " ,." };
   auto tokens{ tokenize( s, d ) };

   reverse( tokens.begin(), tokens.end() );

   for ( const auto& t : tokens )
      cout << t << endl;

   return EXIT_SUCCESS;
}

vector< char* > tokenize( const string& str, const string& delim ) {

   vector< char* > vt;
   char* token;
   char* next{ ( char* )str.data() };

   while ( token = strtok_s( next, delim.data(), &next ) )
      vt.push_back( token );

   return vt;
}
