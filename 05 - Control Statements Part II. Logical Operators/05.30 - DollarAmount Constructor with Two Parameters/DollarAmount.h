// Exercise 5.30: DollarAmount.h

#include <cmath>
#include <string>

class DollarAmount {

public:

   explicit DollarAmount( int64_t dollars, int64_t cents ) {
      amount = dollars * 100 + ( cents >= 0 && cents < 100 ? cents
                                 : throw ( "Incorrect number of cents" ) );
   }

   void add( DollarAmount right ) {
      amount += right.amount;
   }

   void subtract( DollarAmount right ) {
      amount -= right.amount;
   }

   void addInterest( int rate, int divisor ) {
      int64_t iAmount{ ( amount * rate + divisor / 2 ) / divisor };
      DollarAmount interest{ iAmount / 100, iAmount % 100 };
      add( interest );
   }

   std::string toString() const {
      std::string dollars{ std::to_string( amount / 100 ) };
      std::string cents{ std::to_string( std::abs( amount % 100 ) ) };
      return dollars + "." + ( cents.size() == 1 ? "0" : "" ) + cents;
   }

private:

   int64_t amount{};
};