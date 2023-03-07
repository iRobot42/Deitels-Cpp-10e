// Exercise 21.19: ex_21_19.cpp
// Erasing Characters from a string

#include <iostream>
#include <string>
using namespace std;

inline void eraser( string& where, string what ) {
   size_t position;
   while ( ( position = where.find( what ) ) != string::npos )
      where.erase( position, what.size() );
}

int main() {

   string s{ "RUBY byte labyrinth" };

   cout << s << endl;
   eraser( s, "by" );
   eraser( s, "BY" );
   cout << s << endl;

   return EXIT_SUCCESS;
}
