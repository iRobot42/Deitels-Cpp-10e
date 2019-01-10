// Exercise 4.18: ex_04_18.cpp

#include <iostream>

using namespace std;

int main() {

   cout << "N\t5*N\t10*N\t15*N\n";

   int n{ 0 };

   while ( ++n <= 12 )
      cout << n << '\t' << 5 * n << '\t' << 10 * n << '\t' << 15 * n << endl;

   return 0;
}
