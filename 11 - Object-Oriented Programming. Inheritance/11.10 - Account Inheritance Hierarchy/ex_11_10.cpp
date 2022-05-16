// Exercise 11.10: ex_11_10.cpp
// Account Inheritance Hierarchy

#include <iomanip>
#include <iostream>

#include "CheckingAccount.h"
#include "SavingsAccount.h"

using namespace std;

int main() {

   Account account{ 1000.0 };
   SavingsAccount savings_account{ 100.0, 3.0 };
   CheckingAccount checking_account{ 10.0, 0.5 };

   cout << fixed << setprecision( 2 )
      << "Account: $" << account.getBalance()
      << "\nSavingsAccount: $" << savings_account.getBalance()
      << "\nCheckingAccount: $" << checking_account.getBalance() << endl;

   account.credit( 100.0 );
   savings_account.credit( savings_account.calculateInterest() );
   checking_account.credit( 5.0 );

   cout << "\nAdding $100 to Account: $" << account.getBalance()
      << "\nAdding interest to SavingsAccount: $" << savings_account.getBalance()
      << "\nAdding $5 to CheckingAccount: $" << checking_account.getBalance()
      << endl;

   account.debit( 10.0 );
   savings_account.debit( 10.0 );
   checking_account.debit( 10.0 );

   cout << "\nWithdrawing $10 from all accounts...\n"
      << "\nAccount: $" << account.getBalance()
      << "\nSavingsAccount: $" << savings_account.getBalance()
      << "\nCheckingAccount: $" << checking_account.getBalance() << endl;

   return 0;
}
