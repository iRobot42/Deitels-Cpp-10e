// Exercise 14.13: Entry.h

#ifndef ENTRY_H
#define ENTRY_H

#include <string>

class Entry {

public:

   static const short SIZE{ 30 };

   explicit Entry( const std::string& EN = "", const std::string& TR = "" ) {
      set( english, EN );
      set( translation, TR );
   }

   std::string getEnglish() const { return english; }
   std::string getTranslation() const { return translation; }

private:

   char english[ SIZE ];
   char translation[ SIZE ];

   void set( char* word, const std::string& S ) {
      size_t length{ S.size() < SIZE ? S.size() : SIZE-1 };
      S.copy( word, length );
      word[ length ] = '\0';
   }
};

#endif
