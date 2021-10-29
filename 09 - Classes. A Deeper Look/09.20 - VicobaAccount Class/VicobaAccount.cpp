// Exercise 9.20: VicobaAccount.cpp
// VicobaAccount class member-function definitions

#include <iomanip>
#include <iostream>

#include "VicobaAccount.h"

using namespace std;

const double DEFAULT_RATE{ 0.05 };
double VicobaAccount::rate = DEFAULT_RATE;

VicobaAccount::VicobaAccount( double a, int d ) {

   if ( a >= 0.0 && d >= 0 ) {
      amount = a;
      duration = d;
   }
   else throw ( "invalid data" );
}

void VicobaAccount::setRate( const double& R ) {
   rate = ( R < 0.0 ? DEFAULT_RATE : R );
}

void VicobaAccount::setAmount( const double& A ) {
   if ( A >= 0 ) amount = A;
   else throw ( "invalid amount" );
}

void VicobaAccount::setDuration( const int& D ) {
   if ( D >= 0 ) duration = D;
   else throw ( "invalid duration" );
}

double VicobaAccount::getRate() const {
   return rate;
}

double VicobaAccount::getAmount() const {
   return amount;
}

int VicobaAccount::getDuration() const {
   return duration;
}

double VicobaAccount::interest() const {
   return getAmount() * getRate() * getDuration();
}

void VicobaAccount::print() const {
   cout << "Annual interest rate is " << getRate() * 100 << '%' << fixed
      << "\nBorrowed amount is " << setprecision( 2 ) << getAmount() << " TZS"
      << "\nLoan duration is " << getDuration() << " years"
      << "\nTotal interest is " << interest() << " TZS" << endl;
}