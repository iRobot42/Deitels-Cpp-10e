// Exercise 9.20: VicobaAccount.h
// Member functions defined in VicobaAccount.cpp

#ifndef VICOBAACCOUNT_H
#define VICOBAACCOUNT_H

class VicobaAccount {

public:

   explicit VicobaAccount( double = 0.0, int = 0 );

   static void setRate( const double& );
   void setAmount( const double& );
   void setDuration( const int& );

   double getRate() const;
   double getAmount() const;
   int getDuration() const;

   double interest() const;
   void print() const;

private:

   static double rate; // annual interest rate
   double amount; // borrowed amount
   int duration; // loan duration
};

#endif