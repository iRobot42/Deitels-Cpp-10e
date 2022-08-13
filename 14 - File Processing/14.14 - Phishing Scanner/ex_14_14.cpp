// Exercise 14.14: ex_14_14.cpp
// Phishing Scanner

#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

inline void checkStream( const ifstream& S ) {
   if ( !S ) {
      cerr << "File could not be opened" << endl;
      exit( EXIT_FAILURE );
   }
}

inline void output( const string& S, short n ) {
   cout << left << setw( 20 ) << S << right << setw( 3 ) << n << endl;
}

string up( const string& S ) {
   string upper;
   for ( const auto& C : S )
      upper += toupper( C );
   return upper;
}

int main() {

   ifstream ifList{ "phishing.txt", ios::in };
   checkStream( ifList );

   ifstream ifEmail{ "email.txt", ios::in };
   checkStream( ifEmail );

   string email;

   while ( !ifEmail.eof() ) {
      string line;
      getline( ifEmail, line );
      email += line + ' ';
   }

   ifEmail.close();

   cout << "Scan result:\n" << endl;

   short value;
   short total{};

   while ( ifList >> value ) {

      string key;
      getline( ifList >> ws, key );

      short counter{};

      // cached values
      const size_t KEYSIZE{ key.size() };
      const size_t INDEX{ email.size() - KEYSIZE };
      const string KEY{ up( key ) };

      for ( size_t i{}; i < INDEX; ++i )
         if ( up( email.substr( i, KEYSIZE ) ) == KEY )
            counter++;

      short points{ counter * value };
      total += points;

      if ( counter )
         output( to_string( counter ) + "x " + key, points );
   }
   cout << endl;
   output( "TOTAL", total );

   ifList.close();

   return EXIT_SUCCESS;
}
