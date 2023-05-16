// Account.h

#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {

   int accountNumber;
   int pin;
   double availableBalance;
   double totalBalance;

public:

   Account( int, int, double, double );
   bool validatePIN( int ) const;
   double getAvailableBalance() const;
   double getTotalBalance() const;
   void credit( double );
   void debit( double );
   int getAccountNumber() const;
};

#endif