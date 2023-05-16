// CashDispenser.h

#ifndef CASH_DISPENSER_H
#define CASH_DISPENSER_H

class CashDispenser {

   static const int INITIAL_COUNT{ 500 };
   int count;

public:

   CashDispenser();
   void dispenseCash( int );
   bool isSufficientCashAvailable( int ) const;
};

#endif