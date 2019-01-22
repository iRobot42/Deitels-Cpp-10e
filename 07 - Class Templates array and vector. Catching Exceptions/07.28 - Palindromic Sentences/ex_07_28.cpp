// Exercise 7.28: ex_07_28.cpp

#include <iostream>
#include <string>

using namespace std;

bool testPalindrome( string );

int main() {

   string sentence{ "red roses run no risk, sir, on nurses order." };

   cout << sentence << endl;

   if ( testPalindrome( sentence ) )
      cout << "\nPalindrome!" << endl;

   return 0;
}

bool testPalindrome( string s ) {

   if ( s.size() < 2 )
      return true;

   size_t e{ s.size() - 1 };

   // ignore everything except lowercase letters
   if ( s[ 0 ] < 97 || s[ 0 ] > 122 )
      return testPalindrome( s.substr( 1, e ) );
   if ( s[ e ] < 97 || s[ e ] > 122 )
      return testPalindrome( s.substr( 0, e ) );

   if ( s[ 0 ] == s[ e ] )
      return testPalindrome( s.substr( 1, e - 1 ) );

   return false;
}
