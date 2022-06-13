// Exercise 13.14: PhoneNumber.cpp

#include <iomanip>
#include "PhoneNumber.h"

using namespace std;

istream& operator>>( istream& in, PhoneNumber& n ) {

   char number[ 14 + 1 ];
   cin.get( number, 15 );

   if ( cin.gcount() != 14 ||
        number[ 1 ] == '0' || number[ 1 ] == '1' ||
        number[ 6 ] == '0' || number[ 6 ] == '1' ||
        ( number[ 2 ] != '0' && number[ 2 ] != '1' ) )
      cin.clear( ios::failbit );

   if ( cin.good() ) {
      n.areaCode = { number[ 1 ], number[ 2 ], number[ 3 ] };
      n.exchange = { number[ 6 ], number[ 7 ], number[ 8 ] };
      n.line = { number[ 10 ], number[ 11 ], number[ 12 ], number[ 13 ] };
   }
   else {
      cerr << "Incorrect number" << endl;
      exit( 1 );
   }

   return in;
}

ostream& operator<<( ostream& out, const PhoneNumber& N ) {
   out << '(' << N.areaCode << ") " << N.exchange << '-' << N.line;
   return out;
}