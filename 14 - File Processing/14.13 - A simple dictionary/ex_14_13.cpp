// Exercise 14.13: ex_14_13.cpp
// A simple dictionary

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include "Entry.h"

using namespace std;

enum class Menu { VIEW = 1, ADD, SEARCH, QUIT };

void createDictionary( const string& );
Menu select();

int main() {

   const string LANGUAGE( "Belarusian" );
   //createDictionary( LANGUAGE );

   fstream file( LANGUAGE + ".dat", ios::binary | ios::in | ios::app );
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

         cout << left << setw( 32 ) << "English"
                      << setw( 30 ) << LANGUAGE << endl;
         cout << string( 62, '-' ) << endl;
         file.seekg( ios::beg );
         while ( file.read( reinterpret_cast< char* >( &entry ),
                            sizeof( Entry ) ) )
            cout << left << setw( 30 ) << entry.getEnglish() << "  "
                         << setw( 30 ) << entry.getTranslation() << endl;
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

void createDictionary( const string& LANG ) {
   ofstream file( LANG + ".dat", ios::binary | ios::out );
   if ( !file ) {
      cerr << "File could not be created" << endl;
      exit( EXIT_FAILURE );
   }
   file.close();
}

Menu select() {
   cout << "[1] view, [2] add, [3] search, [4] quit: ";
   int choice;
   cin >> choice;
   return static_cast< Menu >( choice );
}
