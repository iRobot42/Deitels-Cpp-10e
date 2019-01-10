// Exercise 4.20: ex_04_20.cpp

#include <iostream>

using namespace std;

int main() {

   unsigned int passes{ 0 };
   unsigned int failures{ 0 };
   unsigned int studentCounter{ 1 };

   while ( studentCounter <= 10 ) {

      cout << "Enter result (1 = pass, 2 = fail): ";
      int result;
      cin >> result;

      if ( result == 1 ) {
         passes++;
         studentCounter++;
      }
      else if ( result == 2 ) {
         failures++;
         studentCounter++;
      }
      else
         cout << "Invalid result!\n";
   }

   cout << "Passed: " << passes << "\nFailed: " << failures << endl;

   if ( passes > 8 )
      cout << "Bonus to instructor!" << endl;
}
