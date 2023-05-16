// BankDatabase.h

#ifndef BANK_DATABASE_H
#define BANK_DATABASE_H

#include <vector>
using namespace std;

#include "Account.h"

class BankDatabase {

   vector< Account > accounts;
   Account* getAccount( int );

public:

   BankDatabase();
   bool authenticateUser( int, int );
   double getAvailableBalance( int );
   double getTotalBalance( int );
   void credit( int, double );
   void debit( int, double );
};

#endif