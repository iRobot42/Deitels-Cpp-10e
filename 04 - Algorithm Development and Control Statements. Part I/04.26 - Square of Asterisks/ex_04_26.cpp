// Exercise 4.26: ex_04_26.cpp

#include <iostream>

using namespace std;

int main() {
      
   int size{ 0 };

   while ( !size ) {
      
      cout << "Size (1-20): ";
      cin >> size;

      if ( size < 1 )
         size = 0;
      else if ( size > 20 )
         size = 0;
   }

   int row{ 0 };

   while ( ++row <= size ) {

      int col{ 0 };

      while ( ++col <= size )

         if ( col == 1 )
            cout << '*';
         else if ( col == size )
            cout << "*\n";
         else if ( row == 1 )
            cout << '*';
         else if ( row == size )
            cout << '*';
         else
            cout << ' ';
   }

   return 0;
}
