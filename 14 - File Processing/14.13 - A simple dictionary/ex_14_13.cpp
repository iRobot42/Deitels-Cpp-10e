// Exercise 14.13: ex_14_13.cpp
// A simple dictionary

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include "Entry.h"

using namespace std;

enum class Menu { VIEW = 1, ADD, SEARCH, QUIT };

Menu select();
inline void output( const string&, const string& );

int main() {

   const string LANGUAGE{ "Belarusian" };

   fstream file{ LANGUAGE + ".dat", ios::binary | ios::in | ios::app };
   if ( !file ) {
      cerr << "File could not be opened" << endl;
      exit( EXIT_FAILURE );
   }

   Entry entry;
   Menu menu;

   while ( ( menu = select() ) != Menu::QUIT ) {

      string english, language;

      cout << endl;
      switch ( menu ) {

      case Menu::VIEW:

         output( "English", LANGUAGE );
         cout << string( Entry::SIZE * 2 + 2, '-' ) << endl;
         file.seekg( ios::beg );
         while ( file.read( reinterpret_cast< char* >( &entry ),
                            sizeof( Entry ) ) )
            output( entry.getEnglish(), entry.getTranslation() );
         break;

      case Menu::ADD:

         cout << "English: ";
         getline( cin >> ws, english );
         cout << LANGUAGE << ": ";
         getline( cin >> ws, language );
         entry = Entry{ english, language };
         file.write( reinterpret_cast< char* >( &entry ), sizeof( Entry ) );
         cout << "New entry added\n";
         break;

      case Menu::SEARCH:

         cout << "Find entry: ";
         getline( cin >> ws, english );
         file.seekg( ios::beg );
         while ( file.read( reinterpret_cast< char* >( &entry ),
                            sizeof( Entry ) ) )
            if ( entry.getEnglish() == english ) {
               cout << "In " << LANGUAGE << ": " << entry.getTranslation()
                  << endl;
               break;
            }
         if ( file.eof() )
            cout << "Entry not found" << endl;
         break;

      default:
         cerr << "Incorrect choice" << endl;
      }

      cout << endl;
      file.clear();
   }

   file.close();
   return EXIT_SUCCESS;
}

Menu select() {
   cout << "[1] view, [2] add, [3] search, [4] quit: ";
   int choice;
   cin >> choice;
   return static_cast< Menu >( choice );
}

void output( const string& S1, const string& S2 ) {
   cout << left << setw( Entry::SIZE ) << S1 << "  "
                << setw( Entry::SIZE ) << S2 << endl;
}
