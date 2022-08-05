// Exercise 14.13: Entry.h

#ifndef ENTRY_H
#define ENTRY_H

#include <string>

class Entry {

   char english[ 30 ];
   char translation[ 30 ];

public:

   explicit Entry( const std::string& EN = "", const std::string& TR = "" ) {
      set( english, EN );
      set( translation, TR );
   }

   void set( char* word, const std::string& S ) {
      size_t length{ S.size() < 30 ? S.size() : 29 };
      S.copy( word, length );
      word[ length ] = '\0';
   }

   std::string getEnglish() const { return english; }
   std::string getTranslation() const { return translation; }
};

#endif
