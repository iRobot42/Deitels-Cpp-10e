// Exercise 3.17: ElectricBillTest.cpp

#include <iostream>
#include "ElectricBill.h"

using namespace std;

int main() {

   double amount;

   cout << "Amount (Tanzanian Shillings): ";
   cin >> amount;

   ElectricBill electricBill( amount );

   cout << "\nAmount paid:    " << electricBill.getAmountPaid() << " TZS"
        << "\nUnits provided: " << electricBill.getUnits() << " kWh"
        << "\nVAT (18%):      " << electricBill.getVAT() << " TZS"
        << "\nREA (3%):       " << electricBill.getREA() << " TZS"
        << "\nEWURA (1%):     " << electricBill.getEWURA() << " TZS"
        << "\nFixed charge:   5000 TZS" << endl;

   return 0;
}
