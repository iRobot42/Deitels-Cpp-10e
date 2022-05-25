// Exercise 13.13: ex_13_13.cpp
// Dealing with extra input characters

#include <iostream>

using namespace std;

int main() {

   const int SIZE{ 80 };
   char first[ SIZE ], last[ SIZE ];
   int year;

   cout << "Name: ";
   cin >> first >> last;
   cin.ignore( SIZE, '\n' );

   cout << "Year: ";
   cin >> year;

   cout << endl << first << ' ' << last << " was built in " << year << endl;

   return 0;
}
