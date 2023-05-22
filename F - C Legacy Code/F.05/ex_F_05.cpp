// Exercise F.5: ex_F_05.cpp

#include <csignal>
#include <iostream>
using namespace std;

void handler( const int );

int main() {

   signal( SIGABRT, handler );
   signal( SIGINT, handler );

   raise( SIGINT );
   abort();

   return EXIT_SUCCESS;
}

void handler( const int s ) {

   switch ( s ) {

      case SIGABRT:
         cerr << "SIGABRT" << endl;
         break;

      case SIGINT:
         cerr << "SIGINT" << endl;
         break;
   }
}
