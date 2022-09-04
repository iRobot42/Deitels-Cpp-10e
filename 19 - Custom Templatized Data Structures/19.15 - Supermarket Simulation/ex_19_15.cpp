// Exercise 19.15: ex_19_15.cpp
// Supermarket Simulation

#include <iostream>
#include "Queue.h"

inline int reset() { return 1 + rand() % 4; }

struct Customer {
   const int ARRIVAL{};
   explicit Customer( const int A ) : ARRIVAL{ A } {};
};

int main() {

   srand( static_cast< unsigned >( time( NULL ) ) );

   Queue< Customer > line;
   int arrival{ reset() }, service{reset()};
   int max_line{};
   int max_wait{};

   for ( int minute{}; minute < 720; ++minute ) {

      if ( !arrival-- ) {
         line.push( Customer( minute ) );
         arrival = reset();
      }

      if ( line.size() > max_line )
         max_line = line.size();

      if ( !line.empty() && !--service ) {
         const int COMPLETION{ minute - line.pop().ARRIVAL };
         if ( COMPLETION > max_wait )
            max_wait = COMPLETION;
         service = reset();
      }
   }
   std::cout << "Longest line: " << max_line << " customer(s)\n"
             << "Longest wait: " << max_wait << " minute(s)";

   return EXIT_SUCCESS;
}
