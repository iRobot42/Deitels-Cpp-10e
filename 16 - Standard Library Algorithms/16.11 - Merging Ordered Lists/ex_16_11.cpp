// Exercise 16.11: ex_16_11.cpp
// Merging Ordered Lists

#include <algorithm>
#include <iostream>
#include <list>

using namespace std;

int main() {

   list< string > list1{ "Alpha", "Bravo", "Charlie" };
   list< string > list2{ "Delta", "Echo", "Foxtrot", "Golf" };
   list< string > result;

   merge( list1.cbegin(), list1.cend(), list2.cbegin(), list2.cend(),
          back_inserter( result ) );

   for ( const auto& word : result )
      cout << word << ' ';

   return EXIT_SUCCESS;
}
