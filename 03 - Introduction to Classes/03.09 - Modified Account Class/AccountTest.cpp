// Exercise 3.9: AccountTest.cpp

#include <iostream>
#include "Account.h"

using namespace std;

int main() {

   Account account1{ "Jane Green", 50 };
   Account account2{ "John Blue", -7 };

   cout << "account1: " << account1.getName() << " balance is $"
      << account1.getBalance();
   cout << "\naccount2: " << account2.getName() << " balance is $"
      << account2.getBalance();

   int withdrawAmount;

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
