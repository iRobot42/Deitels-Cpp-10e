// Exercise 17.31: ex_17_31.cpp
// Stack Unwinding

#include <iostream>
#include <stdexcept>

using namespace std;

void a() { throw 42; }
void b() { a(); }
//void f( int x = 5 ) { x ? f( --x ) : throw x; }

int main() {

   try { b(); }
   catch ( int& i ) { cerr << "Caught: " << i; }

   return EXIT_SUCCESS;
}
