// Withdrawal.h

#ifndef WITHDRAWAL_H
#define WITHDRAWAL_H

#include "Transaction.h"

class Keypad;
class CashDispenser;

class Withdrawal : public Transaction {

   int amount;
   Keypad& keypad;
   CashDispenser& cashDispenser;
   int displayMenuOfAmounts() const;

public:

   Withdrawal( int, Screen&, BankDatabase&, Keypad&, CashDispenser& );
   virtual void execute();
};

#endif