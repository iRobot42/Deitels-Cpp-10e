// Exercise 14.10: ex_14_10.cpp
// Write a series of statements

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Person {

   char lastName[ 15 ];
   char firstName[ 10 ];
   int age;
   int id;

public:

   Person( string = "unassigned", string = "", int = 0 );

   void setFirstName( const string& );
   void setLastName( const string& );
   void setAge( int );
   void setId( int );

   string getFirstName() const;
   string getLastName() const;
   int getAge() const;
   int getId() const;
};

int main() {

   string f, l;
   int a;

   // a

   fstream fPerson{ "nameage.dat", ios::binary | ios::out | ios::in };
   Person person;
   fPerson.seekp( 0 );
   for ( int i{}; i < 100; ++i )
      fPerson.write( reinterpret_cast< char* >( &person ), sizeof( person ) );

   // b

   fPerson.seekp( 0 );
   for ( int i{}; i < 10; ++i ) {
      cin >> f >> l >> a;
      person.setFirstName( f );
      person.setLastName( l );
      person.setAge( a );
      fPerson.write( reinterpret_cast< char* >( &person ), sizeof( person ) );
   }

   // c

   fPerson.seekg( sizeof( person ) * 1 );
   fPerson.read( reinterpret_cast< char* >( &person ), sizeof( person ) );
   if ( person.getLastName().empty() || person.getFirstName().empty()
        || !person.getAge() )
      cout << "No info" << endl;
   else {
      cin >> f >> l >> a;
      person.setFirstName( f );
      person.setLastName( l );
      person.setAge( a );
      fPerson.seekp( sizeof( person ) * 1 );
      fPerson.write( reinterpret_cast< char* >( &person ), sizeof( person ) );
   }

   // d

   person = Person{};
   fPerson.seekp( 0 );
   fPerson.write( reinterpret_cast< char* >( &person ), sizeof( person ) );

   return 0;
}
