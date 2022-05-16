// Exercise 11.10: Account.h

#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {

public:

   explicit Account( double = 0.0 );

   void credit( double );
   void debit( double );

   double getBalance() const;

private:

   double balance;
};

#endif