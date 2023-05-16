// ATM.h

#ifndef ATM_H
#define ATM_H

#include "Screen.h"
#include "Keypad.h"
#include "CashDispenser.h"
#include "DepositSlot.h"
#include "BankDatabase.h"

class Transaction;

class ATM {

   bool userAuthenticated;
   int currentAccountNumber;
   Screen screen;
   Keypad keypad;
   CashDispenser cashDispenser;
   DepositSlot depositSlot;
   BankDatabase bankDatabase;

   void authenticateUser();
   void performTransactions();
   int displayMainMenu() const;

   Transaction* createTransaction( int );

public:

   ATM();
   void run();
};

#endif