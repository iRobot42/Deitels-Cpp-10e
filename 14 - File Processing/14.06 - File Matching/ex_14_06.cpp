// Exercise 14.6: ex_14_06.cpp
// File Matching

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

inline void output( ostream& fout, int acc, const string& fn,
                    const string& ln, double bal ) {
   fout << acc << ' ' + fn + ' ' + ln + ' ' << bal << '\n';
   cout << fixed << setprecision( 2 ) << setw( 4 )
      << acc << ": " + fn + ' ' + ln + ", " << bal << " USD\n";
}

int main() {

   ifstream inTransaction{ "trans.dat", ios::in };
   ifstream inOldMaster{ "oldmast.dat", ios::in };
   ofstream outNewMaster{ "newmast.dat", ios::out };

   if ( !inTransaction || !inOldMaster || !outNewMaster ) {
      cerr << "File could not be opened\n";
      exit( EXIT_FAILURE );
   }

   int tAccount, mAccount;
   double tBalance, mBalance;
   string fName, lName;

   inTransaction >> tAccount >> tBalance;
   inOldMaster >> mAccount >> fName >> lName >> mBalance;

   while ( !inTransaction.eof() ) {

      if ( !inOldMaster.eof() && mAccount < tAccount ) {
         output( outNewMaster, mAccount, fName, lName, mBalance );
         inOldMaster >> mAccount >> fName >> lName >> mBalance;
      }
      else if ( mAccount == tAccount ) {
         output( outNewMaster, mAccount, fName, lName, mBalance + tBalance );
         inTransaction >> tAccount >> tBalance;
         inOldMaster >> mAccount >> fName >> lName >> mBalance;
      }
      else {
         cout << setw( 4 ) << tAccount << ": Unmatched transaction record!\n";
         inTransaction >> tAccount >> tBalance;
      }
   }

   return 0;
}
