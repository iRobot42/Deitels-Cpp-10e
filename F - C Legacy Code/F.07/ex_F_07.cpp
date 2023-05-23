// Exercise F.7: ex_F_07.cpp

#include <fstream>
#include <iostream>
using namespace std;

int main( int argc, char** argv ) {

   // command arguments: input.txt output.txt

   if ( argc != 3 ) {
      cerr << "Invalid command arguments" << endl;
      exit( EXIT_FAILURE );
   }

   ifstream ifs( argv[ 1 ], ios::in );
   ofstream ofs( argv[ 2 ], ios::out );

   if ( !ifs || !ofs ) {
      cerr << "File could not be opened" << endl;
      exit( EXIT_FAILURE );
   }

   string st;
   char c;
   while ( ifs.get( c ) )
      st.push_back( c );
   size_t s{ st.size() };
   while ( s-- )
      ofs.put( st[ s ] );

   ifs.close();
   ofs.close();

   return EXIT_SUCCESS;
}
