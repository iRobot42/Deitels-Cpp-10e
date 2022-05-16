// Exercise 11.10: CheckingAccount.cpp

#include "CheckingAccount.h"

CheckingAccount::CheckingAccount( double b, double f )
   : Account::Account( b ), fee{ f > 0.0 ? f : throw "Incorrect fee" } {
}

void CheckingAccount::credit( double amount ) {
   Account::credit( amount - fee );
}

void CheckingAccount::debit( double amount ) {
   Account::debit( amount + fee );
}