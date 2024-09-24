// Exercise 8.16: ex_08_16.cpp
// Computer Simulator

#include <iomanip>
#include <iostream>

using namespace std;

bool valid( const int* const );

int main() {

   const int SIZE{ 100 };
   int memory[ SIZE ]{};

   // LOAD

   cout << "*** Welcome to Simpletron! ***\n\n"
      "*** Please enter your program one instruction ***\n"
      "*** (or data word) at a time. I will type the ***\n"
      "*** location number and a question mark (?).  ***\n"
      "*** You then type the word for that location. ***\n"
      "*** Type the sentinel -99999 to stop entering ***\n"
      "*** your program. ***\n" << endl;

   const int SENTINEL{ -99999 };
   int instructionCounter{};

   do {

      cout << ( instructionCounter < 10 ? "0" : "" )
         << instructionCounter << " ? ";

      int instruction;
      cin >> instruction;

      if ( instruction == SENTINEL )
         break;

      valid( &instruction )
         ? memory[ instructionCounter ] = instruction
         : instructionCounter--;

   } while ( ++instructionCounter < SIZE );

   cout << "\n*** Program loading completed ***" << endl;

   // EXECUTE

   cout << "*** Program execution begins ***" << endl;

   instructionCounter = 0;
   
   int accumulator{};
   int instructionRegister{};
   int operand{};
   int operationCode{};
   
   bool error{ false };

   do {

      instructionRegister = memory[ instructionCounter ];
      operationCode = instructionRegister / 100;
      operand = instructionRegister % 100;

      switch ( operationCode ) {

         int number;

      case 10: // read
         do {
            cout << "Number: ";
            cin >> number;
         } while ( !valid( &number ) );
         memory[ operand ] = number;
         instructionCounter++;
         break;

      case 11: // write
         cout << "Content is " << memory[ operand ] << endl;
         instructionCounter++;
         break;

      case 20: // load
         accumulator = memory[ operand ];
         instructionCounter++;
         break;

      case 21: // store
         memory[ operand ] = accumulator;
         instructionCounter++;
         break;

      case 30: // add
         number = accumulator + memory[ operand ];
         if ( !valid( &number ) ) {
            cout << "*** Accumulator overflow ***\n"
               "*** Simpletron execution abnormally terminated ***" << endl;
            error = true;
         }
         else {
            accumulator = number;
            instructionCounter++;
         }
         break;

      case 31: // subtract
         number = accumulator - memory[ operand ];
         if ( !valid( &number ) ) {
            cout << "*** Accumulator overflow ***\n"
               "*** Simpletron execution abnormally terminated ***" << endl;
            error = true;
         }
         else {
            accumulator = number;
            instructionCounter++;
         }
         break;

      case 32: // divide
         if ( !memory[ operand ] ) {
            cout << "*** Attempt to divide by zero ***\n"
               "*** Simpletron execution abnormally terminated ***" << endl;
            error = true;
         }
         else {
            accumulator /= memory[ operand ];
            instructionCounter++;
         }
         break;

      case 33: // multiply
         number = accumulator * memory[ operand ];
         if ( !valid( &number ) ) {
            cout << "*** Accumulator overflow ***\n"
               "*** Simpletron execution abnormally terminated ***" << endl;
            error = true;
         }
         else {
            accumulator = number;
            instructionCounter++;
         }
         break;

      case 40: // branch
         instructionCounter = operand;
         break;

      case 41: // branchneg
         accumulator < 0 ? instructionCounter = operand : instructionCounter++;
         break;

      case 42: // branchzero
         !accumulator ? instructionCounter = operand : instructionCounter++;
         break;

      case 43: // halt
         cout << "*** Simpletron has completed its task ***" << endl;
         break;

      default:
         cout << "*** Invalid operation code ***\n"
            "*** Simpletron execution abnormally terminated ***" << endl;
         error = true;
      }

   } while ( operationCode != 43 && !error );

   cout << "*** Program execution completed ***" << endl;

   // DUMP

   cout << "\nREGISTERS:\naccumulator          "
      << setw( 5 ) << showpos << setfill( '0' ) << internal
      << accumulator << "\ninstructionCounter      "
      << setw( 2 ) << noshowpos << setfill ( '0' )
      << instructionCounter << "\ninstructionRegister  "
      << setw( 5 ) << showpos << setfill( '0' ) << internal
      << instructionRegister << "\noperationCode           "
      << setw( 2 ) << noshowpos << setfill( '0' )
      << operationCode << "\noperand                 "
      << setw( 2 )
      << operand << endl;

   cout << "\nMEMORY:\n   " << setfill( ' ' );
   for ( size_t i{}; i <= 9; ++i )
      cout << setw( 6 ) << i;

   for ( int location{}; location < SIZE; ++location ) {

      if ( !( location % 10 ) )
         cout << endl << setw( 3 ) << location;

      cout << ' ' << setw( 5 ) << showpos << setfill( '0' ) << internal
         << memory[ location ];
   }

   cout << endl;
   return 0;
}

bool valid( const int* const WORD_PTR ) {
   return *WORD_PTR >= -9999 && *WORD_PTR <= 9999;
}
