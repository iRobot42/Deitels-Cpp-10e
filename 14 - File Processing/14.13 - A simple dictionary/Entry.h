// Exercise 14.13: Entry.h

#ifndef ENTRY_H
#define ENTRY_H

#include <string>

class Entry {

   char english[ 30 ];
   char translation[ 30 ];

public:

   explicit Entry( const std::string& EN = "", const std::string& TR = "" ) {
      setEnglish( EN );
      setTranslation( TR );
   }

   void setEnglish( const std::string& EN ) {
      size_t length{ EN.size() < 30 ? EN.size() : 29 };
      EN.copy( english, length );
      english[ length ] = '\0';
   }

   void setTranslation( const std::string& TR ) {
      size_t length{ TR.size() < 30 ? TR.size() : 29 };
      TR.copy( translation, length );
      translation[ length ] = '\0';
   }

   std::string getEnglish() const { return english; }
   std::string getTranslation() const { return translation; }
};

#endif