// Exercise 7.14: ex_07_14.cpp

#include <iostream>
#include <vector>

using namespace std;

int main() {

   vector< int > v;
      
   cout << "Enter 20 numbers [10-100]...\n" << endl;

   for ( size_t i{ 0 }; i < 20; ++i ) {

      int number;

      do {
         cout << "Number " << i + 1 << ": ";
         cin >> number;
      } while ( number < 10 || number > 100 );

      bool skip{ false };

      for ( size_t j{ 0 }; j < v.size(); ++j )
         if ( number == v[ j ] ) {
            skip = true;
            break;
         }

      if ( !skip )
         v.push_back( number );
   }

   cout << "\nUnique values:" << endl;

   for ( const int& element : v )
      cout << element << ' ';

   cout << endl;
   return 0;
}
