// Exercise 7.29: ex_07_29.cpp

#include <array>
#include <iostream>

using namespace std;

const size_t SIZE{ 8 };
bool queen( array< array< bool, SIZE >, SIZE >&, int );

int main() {

   array< array< bool, ::SIZE >, ::SIZE > board{};

   queen( board, 0 );

   for ( const auto& row : board ) {
      for ( const auto& element : row )
         cout << ' ' << ( element ? 'Q' : '.' );
      cout << endl;
   }

   return 0;
}

bool queen( array< array< bool, ::SIZE >, ::SIZE >& a, int col ) {

   if ( col == ::SIZE )
      return true;
   
   for ( int row{}; row < ::SIZE; ++row ) {

      bool safe{ true };

      for ( int shift{ 1 }; shift <= col && safe; ++shift ) {

         const int RM{ row - shift };
         const int RP{ row + shift };
         const int CM{ col - shift };

         if ( RM >= 0 && a[ RM ][ CM ] || a[ row ][ CM ]
            || RP < ::SIZE && a[ RP ][ CM ] )
            safe = false;
      }

      if ( safe ) {

         a[ row ][ col ] = true;
         if ( queen( a, col + 1 ) )
            return true;
         a[ row ][ col ] = false;
      }
   }

   return false;
}
