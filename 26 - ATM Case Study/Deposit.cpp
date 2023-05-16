// Deposit.cpp

#include "Deposit.h"
#include "Screen.h"
#include "BankDatabase.h"
#include "Keypad.h"
#include "DepositSlot.h"

static const int CANCELED{};

Deposit::Deposit( int userAccountNumber, Screen& atmScreen,
                  BankDatabase& atmBankDatabase, Keypad& atmKeypad,
                  DepositSlot& atmDepositSlot ) :
   Transaction( userAccountNumber, atmScreen, atmBankDatabase ),
   keypad( atmKeypad ), depositSlot( atmDepositSlot ), amount( 0.0 ) {
}

void Deposit::execute() {

   BankDatabase& bankDatabase{ getBankDatabase() };
   Screen& screen{ getScreen() };
   amount = promptForDepositAmount();

   if ( amount != CANCELED ) {

      screen.displayMessage( "\nPlease insert a deposit envelope containing " );
      screen.displayDollarAmount( amount );
      screen.displayMessageLine( " in the deposit slot." );

      if ( depositSlot.isEnvelopeReceived() ) {

         screen.displayMessageLine( "\nYour envelope has been received."
            "\nNOTE: The money deposited will not be available until we"
            "\nverify the amount of any enclosed cash, and any enclosed "
            "checks clear." );

         bankDatabase.credit( getAccountNumber(), amount );
      }
      else screen.displayMessageLine( "\nYou did not insert an "
         "envelope, so the ATM has canceled your transaction." );
   }
   else screen.displayMessageLine( "\nCanceling transaction..." );
}

double Deposit::promptForDepositAmount() const {

   Screen& screen{ getScreen() };

   screen.displayMessage( "\nPlease enter a deposit amount in "
      "CENTS (or 0 to cancel): " );
   int input{ keypad.getInput() };

   return input == CANCELED ? CANCELED : static_cast< double >( input ) / 100;
}