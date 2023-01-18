// Exercise 21.11: ex_21_11.cpp
// Sentence letter statistics

#include <iostream>
#include <string>
using namespace std;

int main() {

   string sentence;

   cout << "Sentence: ";
   getline( cin, sentence );

   char character;

   cout << "Character: ";
   cin >> character;

   size_t counter{};

   for ( const auto& CHARACTER : sentence )
      if ( tolower( CHARACTER ) == tolower( character ) )
         counter++;

   if ( counter )
      cout << "Found " << counter << " time(s)";
   else
      cout << "Not found";
   cout << endl;

   return EXIT_SUCCESS;
}
