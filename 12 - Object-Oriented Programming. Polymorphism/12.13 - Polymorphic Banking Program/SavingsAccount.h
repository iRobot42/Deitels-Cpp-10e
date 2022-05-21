// Exercise 12.13: SavingsAccount.h

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account {

public:

   explicit SavingsAccount( double = 0.0, double = 0.0 );
   virtual ~SavingsAccount() = default;

   double calculateInterest() const;

private:

   double rate; // %
};

#endif