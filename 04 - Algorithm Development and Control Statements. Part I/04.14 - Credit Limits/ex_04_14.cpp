// Exercise 4.14: ex_04_14.cpp

#include <iomanip>
#include <iostream>

using namespace std;

int main() {

   int account_number;

   double beginning_balance;
   double total_charges;
   double total_credits;
   double credit_limit;
   double new_balance;

   cout << setprecision( 2 ) << fixed;

   cout << "Enter account number (or -1 to quit): ";
   cin >> account_number;

   while ( account_number != -1 ) {

      cout << "Enter beginning balance: ";
      cin >> beginning_balance;
      cout << "Enter total charges: ";
      cin >> total_charges;
      cout << "Enter total credits: ";
      cin >> total_credits;
      cout << "Enter credit limit: ";
      cin >> credit_limit;

      new_balance = beginning_balance + total_charges - total_credits;

      cout << "New balance is " << new_balance << endl;

      if ( new_balance > credit_limit )
         cout << "Account:      " << account_number
            << "\nCredit limit: " << credit_limit
            << "\nBalance:      " << new_balance
            << "\nCredit Limit Exceeded." << endl;

      cout << "\nEnter Account Number (or -1 to quit): ";
      cin >> account_number;
   }

   return 0;
}
