// Exercise 14.7: ex_14_07.cpp
// File Matching Test Data

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int main() {

   ofstream ofMaster{ "oldmast.dat", ios::out };
   ofstream ofTransaction{ "trans.dat", ios::out };

   if ( !ofMaster || !ofTransaction ) {
      cerr << "File could not be opened\n";
      exit( EXIT_FAILURE );
   }

   int number;
   string name;
   double balance;

   cout << "Enter account number, full name and balance (EOF to end)\n: ";
   while ( cin >> number >> quoted( name ) >> balance ) {
      ofMaster << number << ' ' + name + ' ' << balance << '\n';
      cout << ": ";
   }

   ofMaster.close();
   cin.clear();

   cout << "\nEnter account number and transaction amount (EOF to end)\n: ";
   while ( cin >> number >> balance ) {
      ofTransaction << number << ' ' << balance << '\n';
      cout << ": ";
   }

   ofTransaction.close();
   cout << "\nSaved!" << endl;

   return 0;
}
