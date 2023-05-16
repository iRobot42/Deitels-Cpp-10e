// Transaction.h

#ifndef TRANSACTION_H
#define TRANSACTION_H

class Screen;
class BankDatabase;

class Transaction {

   int accountNumber;
   Screen& screen;
   BankDatabase& bankDatabase;

public:

   Transaction( int, Screen&, BankDatabase& );
   virtual ~Transaction() {}
   
   virtual void execute() = 0;

   int getAccountNumber() const;
   Screen& getScreen() const;
   BankDatabase& getBankDatabase() const;
};

#endif