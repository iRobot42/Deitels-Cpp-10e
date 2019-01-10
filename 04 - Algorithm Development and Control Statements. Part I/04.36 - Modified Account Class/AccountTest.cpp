// Exercise 4.36: AccountTest.cpp

#include <iomanip>
#include <iostream>
#include "Account.h"

using namespace std;

int main() {

   cout << setprecision( 2 ) << fixed;

   Account account1{ "Jane Green", 50.0 };
   Account account2{ "John Blue", -7.0 };

   cout << "account1: " << account1.getName() << " balance is $"
      << account1.getBalance();
   cout << "\naccount2: " << account2.getName() << " balance is $"
      << account2.getBalance();

   double withdrawAmount;

   cout << "\n\nEnter withdraw amount for account1: ";
   cin >> withdrawAmount;

   account1.withdraw( withdrawAmount );

   cout << "\naccount1: " << account1.getName() << " balance is $"
      << account1.getBalance();
   cout << "\naccount2: " << account2.getName() << " balance is $"
      << account2.getBalance();

   cout << "\n\nEnter withdraw amount for account2: ";
   cin >> withdrawAmount;

   account2.withdraw( withdrawAmount );

   cout << "\naccount1: " << account1.getName() << " balance is $"
      << account1.getBalance();
   cout << "\naccount2: " << account2.getName() << " balance is $"
      << account2.getBalance() << endl;

   return 0;
}
