// Exercise 5.21: ex_05_21.cpp

#include <iostream>

using namespace std;

int main() {

   for ( int row{ 1 }; row <= 10; ++row ) {

      for ( int col{ 1 }; col <= row; ++col )
         cout << '*';
      for ( int col{ 10 }; col > row; --col )
         cout << ' ';

      cout << '\t';

      for ( int col{ 10 }; col >= row; --col )
         cout << '*';
      for ( int col{ 1 }; col < row; ++col )
         cout << ' ';

      cout << '\t';

      for ( int col{ 1 }; col < row; ++col )
         cout << ' ';
      for ( int col{ 10 }; col >= row; --col )
         cout << '*';

      cout << '\t';

      for ( int col{ 10 }; col > row; --col )
         cout << ' ';
      for ( int col{ 1 }; col <= row; ++col )
         cout << '*';

      cout << endl;
   }

   return 0;
}
