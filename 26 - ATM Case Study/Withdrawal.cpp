// Withdrawal.cpp

#include "Withdrawal.h"
#include "Screen.h"
#include "BankDatabase.h"
#include "Keypad.h"
#include "CashDispenser.h"

static const int CANCELED{ 6 };

Withdrawal::Withdrawal( int userAccountNumber, Screen& atmScreen,
                        BankDatabase& atmBankDatabase, Keypad& atmKeypad,
                        CashDispenser& atmCashDispenser ) :
   Transaction( userAccountNumber, atmScreen, atmBankDatabase ),
   keypad( atmKeypad ), cashDispenser( atmCashDispenser ), amount( 0 ) {
}

void Withdrawal::execute() {

   bool cashDispensed{};
   bool transactionCanceled{};
   BankDatabase& bankDatabase{ getBankDatabase() };
   Screen& screen{ getScreen() };

   do {

      int selection{ displayMenuOfAmounts() };

      if ( selection != CANCELED ) {

         amount = selection;
         double availableBalance{
            bankDatabase.getAvailableBalance( getAccountNumber() ) };

         if ( amount <= availableBalance ) {

            if ( cashDispenser.isSufficientCashAvailable( amount ) ) {
               
               bankDatabase.debit( getAccountNumber(), amount );
               cashDispenser.dispenseCash( amount );
               cashDispensed = true;

               screen.displayMessageLine( "\nPlease take your cash." );
            }
            else screen.displayMessageLine(
               "\nInsufficient cash available in the ATM.\n"
               "\nPlease choose a smaller amount." );
         }
         else screen.displayMessageLine(
            "\nInsufficient funds in your account.\n"
            "\nPlease choose a smaller amount." );
      }
      else {
         screen.displayMessageLine( "\nCanceling transaction..." );
         transactionCanceled = true;
      }
   } while ( !cashDispensed && !transactionCanceled );
}

int Withdrawal::displayMenuOfAmounts() const {

   int userChoice{};
   Screen& screen{ getScreen() };
   int amounts[]{ 0, 20, 40, 60, 100, 200 };

   while ( !userChoice ) {

      screen.displayMessageLine( "\nWithdrawal options:" );
      screen.displayMessageLine( "1 - $20" );
      screen.displayMessageLine( "2 - $40" );
      screen.displayMessageLine( "3 - $60" );
      screen.displayMessageLine( "4 - $100" );
      screen.displayMessageLine( "5 - $200" );
      screen.displayMessageLine( "6 - Cancel transaction" );
      screen.displayMessage( "\nChoose a withdrawal option (1-6): " );

      int input{ keypad.getInput() };

      switch ( input ) {

         case 1:
         case 2:
         case 3:
         case 4:
         case 5:
            userChoice = amounts[ input ];
            break;
         case CANCELED:
            userChoice = CANCELED;
            break;
         default:
            screen.displayMessageLine( "\nInvalid selection. Try again." );
      }
   }
   return userChoice;
}