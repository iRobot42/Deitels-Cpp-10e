// Exercise 22.45: ex_22_45.cpp
// Writing the Word Equivalent of a Check Amount

#include <cstring>
#include <iostream>
using namespace std;

void print( const char* );
int convert( const char* );

int main() {

   print( "98,765.43" );
   print( "12,345.67" );
   print( "1,000.00" );
   print( "101.01" );
   print( "42.69" );
   print( "3.14" );

   return EXIT_SUCCESS;
}

void print( const char* c ) {

   cout << c << " => ";
   size_t l{ strlen( c ) };
   if ( l > 7 && convert( c ) ) cout << " THOUSAND ";
   const char* p( strchr( c, ',' ) );
   if ( l > 3 && convert( p ? p + 1 : c ) ) cout << ' ';
   cout << "and " << strchr( c, '.' ) + 1 << "/100" << endl;
}

int convert( const char* c ) {

   const char u20[][ 10 ]{ "", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX",
      "SEVEN", "EIGHT", "NINE", "TEN", "ELEVEN", "TWELVE", "THIRTEEN",
      "FOURTEEN", "FIFTEEN", "SIXTEEN", "SEVENTEEN", "EIGHTEEN", "NINETEEN" };
   const char d10[][ 8 ]{ "", "", "TWENTY", "THIRTY", "FORTY", "FIFTY", "SIXTY",
      "SEVENTY", "EIGHTY", "NINETY" };
   int n{ atoi( c ) };

   if ( n / 100 )
      cout << u20[ n / 100 ] << " HUNDRED ";
   if ( ( n %= 100 ) < 20 )
      cout << u20[ n ];
   else {
      cout << d10[ n / 10 ];
      if ( n % 10 )
         cout << ' ' << u20[ n % 10 ];
   }

   return n;
}
