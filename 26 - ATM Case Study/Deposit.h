// Deposit.h

#ifndef DEPOSIT_H
#define DEPOSIT_H

#include "Transaction.h"

class Keypad;
class DepositSlot;

class Deposit : public Transaction {

   double amount;
   Keypad& keypad;
   DepositSlot& depositSlot;
   double promptForDepositAmount() const;

public:

   Deposit( int, Screen&, BankDatabase&, Keypad&, DepositSlot& );
   virtual void execute();
};

#endif