// Exercise 12.13: ex_12_13.cpp
// Polymorphic Banking Program Using Account Hierarchy

#include <iomanip>
#include <iostream>
#include <typeinfo>
#include <vector>

#include "CheckingAccount.h"
#include "SavingsAccount.h"

using namespace std;

int main() {

   vector< Account* > accounts{
      new SavingsAccount{ 100.0, 3.0 },
      new CheckingAccount{ 10.0, 0.5 },
   };

   cout << fixed << setprecision( 2 );

   for ( Account* accountPtr : accounts ) {

      double amount;

      cout << "Balance is $" << accountPtr->getBalance() << " ("
         << typeid( *accountPtr ).name() << ")\nWithdraw amount: $";
      cin >> amount;
      accountPtr->debit( amount );

      cout << "Deposit amount: $";
      cin >> amount;
      accountPtr->credit( amount );

      SavingsAccount* derivedPtr{ dynamic_cast< SavingsAccount* >( accountPtr ) };

      if ( derivedPtr ) {
         cout << "Adding the interest to the balance..." << endl;
         derivedPtr->credit( derivedPtr->calculateInterest() );
      }

      if ( accountPtr )
         cout << "Updated balance is $" << accountPtr->getBalance() << "\n\n";
   }

   return 0;
}
