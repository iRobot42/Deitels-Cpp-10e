// Exercise 14.11: Tool.h

#ifndef TOOL_H
#define TOOL_H

#include <string>

class Tool {

   int    id;
   char   name[ 20 ];
   int    quantity;
   double cost;

public:

   explicit Tool( int = 0, const std::string& = "", int = 0, double = 0.0 );

   void setID( int );
   void setName( const std::string& );
   void setQuantity( int );
   void setCost( double );

   int         getID() const;
   std::string getName() const;
   int         getQuantity() const;
   double      getCost() const;
};

#endif