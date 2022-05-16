// Exercise 11.10: SavingsAccount.cpp

#include "SavingsAccount.h"

SavingsAccount::SavingsAccount( double b, double r )
   : Account::Account( b ), rate{ r > 0.0 ? r : throw "Incorrect rate" } {
}

double SavingsAccount::calculateInterest() const {
   return getBalance() * rate / 100;
}