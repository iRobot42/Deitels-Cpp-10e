// Screen.h

#ifndef SCREEN_H
#define SCREEN_H

#include <string>
using namespace std;

class Screen {

public:

   void displayMessage( string ) const;
   void displayMessageLine( string ) const;
   void displayDollarAmount( double ) const;
};

#endif