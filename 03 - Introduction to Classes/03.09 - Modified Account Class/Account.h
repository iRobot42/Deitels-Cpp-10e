
// Exercise 3.9: Account.h

#include <string>

class Account {

public:

   Account( std::string accountName, int initialBalance )
      : name{ accountName } {

      if ( initialBalance > 0 )
         balance = initialBalance;
   }

   void deposit( int depositAmount ) {
      if ( depositAmount > 0 )
         balance = balance + depositAmount;
   }

   void withdraw( int withdrawAmount ) {
      if ( withdrawAmount > balance )
         std::cout << "Withdrawal amount exceeded account balance.\n";
      if ( withdrawAmount <= balance )
         balance = balance - withdrawAmount;
   }

   int getBalance() const {
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
   int balance{ 0 };
};
