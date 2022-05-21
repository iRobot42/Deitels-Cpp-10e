// Exercise 12.13: Account.h

#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {

public:

   explicit Account( double = 0.0 );
   virtual ~Account() = default;

   virtual void credit( double );
   virtual void debit( double );

   double getBalance() const;

private:

   double balance;
};

#endif