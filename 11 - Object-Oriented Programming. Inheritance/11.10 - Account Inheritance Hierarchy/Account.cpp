// Exercise 11.10: Account.cpp

#include <iostream>
#include "Account.h"

using namespace std;

Account::Account( double b ) {
   if ( b >= 0.0 )
      balance = b;
   else {
      balance = 0.0;
      cout << "Incorrect initial balance" << endl;
   }
}

void Account::credit( double amount ) {
   if ( amount >= 0.0 ) balance += amount;
   else cout << "Incorrect credit amount" << endl;
}

void Account::debit( double amount ) {
   if ( amount <= balance ) balance -= amount;
   else cout << "Debit amount exceeded account balance" << endl;
}

double Account::getBalance() const {
   return balance;
}