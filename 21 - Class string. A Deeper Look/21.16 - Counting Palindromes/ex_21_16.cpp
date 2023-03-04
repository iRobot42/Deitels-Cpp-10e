// Exercise 21.16: ex_21_16.cpp
// Counting Palindromes

#include <iostream>
#include <string>
using namespace std;

bool palindrome( const string& WORD ) {

   if ( WORD.empty() ) return false;
   if ( WORD.size() == 1 ) return true;

   auto front{ WORD.cbegin() };
   auto back{ WORD.crbegin() };

   const size_t N{ WORD.size() / 2 - 1 };
   for ( size_t i{}; i <= N; ++i )
      if ( tolower( *front++ ) != tolower( *back++ ) )
         return false;

   return true;
}

inline void process( string& wrd, size_t& cnt ) {

   if ( !wrd.empty() ) {
      cout << wrd << ' ';
      if ( palindrome( wrd ) )
         cnt++;
      wrd.clear();
   }
}

int main() {

   string sentence;

   cout << "Sentence: ";
   getline( cin, sentence );

   string word;
   size_t count{};

   cout << "Words: ";
   for ( const auto& CHAR : sentence )
      if ( isalpha( CHAR ) ) word += CHAR;
      else process( word, count );
   process( word, count ); // in case the last CHAR was a letter

   cout << "\nPalindromes: " << count << endl;

   return EXIT_SUCCESS;
}
