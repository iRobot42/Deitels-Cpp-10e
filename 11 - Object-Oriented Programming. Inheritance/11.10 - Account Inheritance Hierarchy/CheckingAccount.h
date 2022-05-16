// Exercise 11.10: CheckingAccount.h

#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "Account.h"

class CheckingAccount : public Account {

public:

   explicit CheckingAccount( double = 0.0, double = 0.0 );

   void credit( double );
   void debit( double );

private:

   double fee;
};

#endif