// Exercise 14.11: ex_14_11.cpp
// Hardware Inventory

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#include "Tool.h"

using namespace std;

enum class Menu{ LIST = 1, NEW, UPDATE, DELETE, END };

void createFile();
Menu select();
inline void enterID( int& );

int main() {

   //createFile();

   fstream file( "hardware.dat", ios::binary | ios::in | ios::out );
   if ( !file ) {
      cerr << "File could not be opened\n";
      exit( EXIT_FAILURE );
   }

   Tool tool;
   Menu menu;

   while ( ( menu = select() ) != Menu::END ) {

      int id;
      string name;
      int quantity;
      double cost;

      cout << endl;
      switch ( menu ) {

      case Menu::LIST:

         cout << "  #  Tool name               Quantity        Cost\n"
            << "--------------------------------------------------\n";
         file.seekg( 0 );
         while ( file.read( reinterpret_cast< char* >( &tool ), sizeof( Tool ) ) )
            if ( !tool.getName().empty() )
               cout << fixed << setprecision( 2 )
                  <<          setw(  3 ) << tool.getID()       << "  "
                  << left  << setw( 20 ) << tool.getName()     << "  "
                  << right << setw( 10 ) << tool.getQuantity() << "  "
                  <<          setw( 10 ) << tool.getCost()     << endl;
         break;

      case Menu::NEW:

         enterID( id );
         file.seekg( sizeof( Tool ) * id );
         file.read( reinterpret_cast< char* >( &tool ), sizeof( Tool ) );
         if ( !tool.getName().empty() )
            cout << "Record #" << id << " already exists\n";
         else {
            cout << "Tool: ";      getline( cin >> ws, name );
            cout << "Quantity: ";  cin >> quantity;
            cout << "Cost: ";      cin >> cost;
            tool = Tool{ id, name, quantity, cost };
            file.seekp( sizeof( Tool ) * id );
            file.write( reinterpret_cast< char* >( &tool ), sizeof( Tool ) );
         }
         break;

      case Menu::UPDATE:

         enterID( id );
         file.seekg( sizeof( Tool ) * id );
         file.read( reinterpret_cast< char* >( &tool ), sizeof( Tool ) );
         if ( tool.getName().empty() )
            cout << "Record #" << id << " is empty\n";
         else {
            int newID;
            cout << "New ";             enterID( newID );
            cout << "New tool name: ";  getline( cin >> ws, name );
            cout << "New quantity: ";   cin >> quantity;
            cout << "New cost: ";       cin >> cost;
            file.seekp( sizeof( Tool ) * id );
            if ( newID != id ) {
               tool = Tool{ id };
               file.write( reinterpret_cast< char* >( &tool ), sizeof( Tool ) );
               cout << "Record #" << id << " deleted\n";
               file.seekp( sizeof( Tool ) * newID );
            }
            tool = Tool{ newID, name, quantity, cost };
            file.write( reinterpret_cast< char* >( &tool ), sizeof( Tool ) );
            cout << "Record #" << newID << " updated\n";
         }
         break;

      case Menu::DELETE:

         enterID( id );
         file.seekg( sizeof( Tool ) * id );
         file.read( reinterpret_cast< char* >( &tool ), sizeof( Tool ) );
         if ( tool.getName().empty() )
            cout << "Record #" << id << " is empty\n";
         else {
            tool = Tool{ id };
            file.seekp( sizeof( Tool ) * id );
            file.write( reinterpret_cast< char* >( &tool ), sizeof( Tool ) );
            cout << "Record #" << id << " has been deleted\n";
         }
         break;

      default:
         cerr << "Incorrect choice\n";
      }

      cout << endl;
      file.clear();
   }

   file.close();

   return 0;
}

void createFile() {
   ofstream file( "hardware.dat", ios::binary | ios::out );
   if ( !file ) {
      cerr << "File could not be created\n";
      exit( EXIT_FAILURE );
   }
   Tool tool;
   file.seekp( 0 );
   for ( int i{}; i < 100; ++i ) {
      tool.setID( i );
      file.write( reinterpret_cast< char* >( &tool ), sizeof( Tool ) );
   }
   file.close();
}

Menu select() {
   cout << "[1] list, [2] new, [3] update, [4] delete, [5] end: ";
   int choice;
   cin >> choice;
   return static_cast< Menu >( choice );
}

void enterID( int& id ) {
   do {
      cout << "ID: ";
      cin >> id;
   } while ( id < 0 || id > 99 );
}
