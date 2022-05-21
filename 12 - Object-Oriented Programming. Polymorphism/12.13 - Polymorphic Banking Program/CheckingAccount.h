// Exercise 12.13: CheckingAccount.h

#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "Account.h"

class CheckingAccount : public Account {

public:

   explicit CheckingAccount( double = 0.0, double = 0.0 );
   virtual ~CheckingAccount() = default;

   virtual void credit( double ) override;
   virtual void debit( double ) override;

private:

   double fee;
};

#endif