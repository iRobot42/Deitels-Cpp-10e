// Exercise 4.36: Account.h

#include <string>

class Account {

public:

   Account( std::string accountName, double initialBalance )
      : name{ accountName } {

      if ( initialBalance > 0.0 )
         balance = initialBalance;
   }

   void deposit( double depositAmount ) {
      if ( depositAmount > 0.0 )
         balance += depositAmount;
   }

   void withdraw( double withdrawAmount ) {
      if ( withdrawAmount > balance )
         std::cout << "Withdrawal amount exceeded account balance.\n";
      if ( withdrawAmount <= balance )
         balance -= withdrawAmount;
   }

   double getBalance() const {
      return balance;
   }

   void setName( std::string accountName ) {
      name = accountName;
   }

   std::string getName() const {
      return name;
   }

private:

   std::string name;
   double balance{ 0.0 };
};
