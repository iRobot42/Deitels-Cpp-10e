// Exercise 5.28: ex_05_28.cpp

#include <iostream>

using namespace std;

int main() {

   cout << "\"The Twelve Days of Christmas\"\n\n";

   for ( int day{ 1 }; day <= 12; ++day ) {

      cout << "On the ";

      switch ( day ) {
      case 1: cout << "first"; break;
      case 2: cout << "second"; break;
      case 3: cout << "third"; break;
      case 4: cout << "fourth"; break;
      case 5: cout << "fifth"; break;
      case 6: cout << "sixth"; break;
      case 7: cout << "seventh"; break;
      case 8: cout << "eighth"; break;
      case 9: cout << "ninth"; break;
      case 10: cout << "tenth"; break;
      case 11: cout << "eleventh"; break;
      case 12: cout << "twelfth"; break;
      }

      cout << " day of Christmas\nMy true love sent to me\n";

      switch ( day ) {
      case 12: cout << "Twelve drummers drumming,\n";
      case 11: cout << "Eleven pipers piping,\n";
      case 10: cout << "Ten lords a-leaping,\n";
      case 9: cout << "Nine ladies dancing,\n";
      case 8: cout << "Eight maids a-milking,\n";
      case 7: cout << "Seven swans a-swimming,\n";
      case 6: cout << "Six geese a-laying,\n";
      case 5: cout << "Five golden rings,\n";
      case 4: cout << "Four calling birds,\n";
      case 3: cout << "Three french hens,\n";
      case 2: cout << "Two turtle doves and\n";
      case 1: cout << "A partridge in a pear tree.\n";
      }

      cout << endl;
   }

   return 0;
}
