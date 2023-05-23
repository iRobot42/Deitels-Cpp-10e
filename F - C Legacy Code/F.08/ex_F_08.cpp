// Exercise F.8: ex_F_08.cpp

#include <iostream>
using namespace std;

int main() {

   int s{ 7 }, r{}, c;
   cout << "Side: " << s << endl;

R: cout << endl;
   if ( ++r > s ) goto E;
   c = 0;
C: if ( ++c > s ) goto R;
   cout << ' ' << '*';
   goto C;

E: return EXIT_SUCCESS;
}
