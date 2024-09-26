// Exercise 8.15: ex_08_15.cpp
// Machine-Language Programming

#include <iostream>

using namespace std;

int main() {

   const int SIZE{ 100 };
   int memory[ SIZE ]{};
   int* loc_ptr{ memory };

   // LOAD

   cout << "Write your SML program. 11111 to end.\n" << endl;

   do {

      cout << "> ";
      int instruction;
      cin >> instruction;

      if ( instruction == 11111 )
         break;
      if ( instruction < -9999 || instruction > 9999 )
         continue;

      *loc_ptr++ = instruction;

   } while ( loc_ptr < &memory[ SIZE ] );
   
   // EXECUTE

   cout << endl;

   loc_ptr = memory;
   int accumulator{};

   do {

      switch ( *loc_ptr / 100 ) {

         int number;

      case 10: // read
         do {
            cout << "Number: ";
            cin >> number;
         } while ( number < -9999 || number > 9999 );
         memory[ *loc_ptr % 100 ] = number;
         break;
      
      case 11: // write
         cout << endl << memory[ *loc_ptr % 100 ] << endl;
         break;
      
      case 20: // load
         accumulator = memory[ *loc_ptr % 100 ];
         break;
      
      case 21: // store
         memory[ *loc_ptr % 100 ] = accumulator;
         break;
      
      case 30: // add
         number = accumulator + memory[ *loc_ptr % 100 ];
         if ( number < -9999 || number > 9999 ) {
            cout << "Out of range!" << endl;
            loc_ptr = &memory[ SIZE ];
         }
         else accumulator = number;
         break;
      
      case 31: // subtract
         number = accumulator - memory[ *loc_ptr % 100 ];
         if ( number < -9999 || number > 9999 ) {
            cout << "Out of range!" << endl;
            loc_ptr = &memory[ SIZE ];
         }
         else accumulator = number;
         break;
      
      case 32: // divide
         if ( !memory[ *loc_ptr % 100 ] ) {
            cout << "Division by zero!" << endl;
            loc_ptr = &memory[ SIZE ];
         }
         else accumulator /= memory[*loc_ptr % 100];
         break;
      
      case 33: // multiply
         number = accumulator * memory[ *loc_ptr % 100 ];
         if ( number < -9999 || number > 9999 ) {
            cout << "Out of range!" << endl;
            loc_ptr = &memory[ SIZE ];
         }
         else accumulator = number;
         break;
      
      case 40: // branch
         loc_ptr = &memory[ *loc_ptr % 100 ] - 1;
         break;
      
      case 41: // branchneg
         if ( accumulator < 0 )
            loc_ptr = &memory[ *loc_ptr % 100 ] - 1;
         break;
      
      case 42: // branchzero
         if ( !accumulator )
            loc_ptr = &memory[ *loc_ptr % 100 ] - 1;
         break;
      
      case 43: // halt
      default:
         loc_ptr = &memory[ SIZE ];
      }

   } while ( ++loc_ptr < &memory[ SIZE ] );

   return 0;
}
