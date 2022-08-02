// Exercise 14.11: Tool.cpp

#include <iomanip>
#include <iostream>
#include "Tool.h"

using namespace std;

Tool::Tool( int i, const string& n, int q, double c ) {
   setID( i );
   setName( n );
   setQuantity( q );
   setCost( c );
};

void Tool::setName( const string& n ) {
   size_t length{ n.size() < 20 ? n.size() : 19 };
   n.copy( name, length );
   name[ length ] = '\0';
}
void Tool::setID( int i )       { id = i < 0 ? 0 : i; }
void Tool::setQuantity( int q ) { quantity = q < 0 ? 0 : q; }
void Tool::setCost( double c )  { cost = c < 0.0 ? 0.0 : c; }

int    Tool::getID() const       { return id; }
string Tool::getName() const     { return name; }
int    Tool::getQuantity() const { return quantity; }
double Tool::getCost() const     { return cost; }