// Exercise 22.28: ex_22_28.cpp
// Memory Handling Functions

#include <iostream>
using namespace std;

void*  mem_cpy  ( void*, const void*, size_t );
void*  mem_move ( void*, const void*, size_t );
int    mem_cmp  ( const void*, const void*, size_t );
void*  mem_chr  ( const void*, int, size_t );
void*  mem_set  ( void*, int, size_t );

int main() {

   char s[]{ "source" };
   char d[]{ "destination" };

   cout << "Initial:\n"
      << "\n s : " << &s << " : " << s
      << "\n d : " << &d << " : " << d << endl;

   void* ch{ mem_cpy( d, s, sizeof( s ) ) };

   cout << "\nmem_cpy( d, s, sizeof( s ) ):\n"
      << "\n s : " << &s << " : " << s
      << "\n d : " << ch << " : " << d << endl;

   ch = mem_move( s, s + 3, 3 );

   cout << "\nmem_move( s, s + 3, 3 ):\n"
      << "\n s : " << ch << " : " << s << endl;

   strncpy_s( s, "BMW M3", sizeof( s ) );
   strncpy_s( d, "BMW M5", sizeof( d ) );

   cout << "\nNew values:\n"
      << "\n s : " << &s << " : " << s
      << "\n d : " << &d << " : " << d << endl;

   cout << "\nmem_cmp( s, d, 5 ) == " << mem_cmp( s, d, 5 )
      << "\nmem_cmp( s, d, 6 ) == " << mem_cmp( s, d, 6 )
      << "\nmem_cmp( d, s, sizeof( d ) ) == " << mem_cmp( d, s, sizeof( d ) )
      << endl;

   cout << "\nmem_chr( s, 'W', 2 ) : " << mem_chr( s, 'W', 2 )
      << "\nmem_chr( s, 'W', 3 ) : " << mem_chr( s, 'W', 3 )
      << "\nmem_chr( s, '3', 6 ) : " << mem_chr( s, '3', 6 ) << endl;

   cout << "\nmem_set( s + 1, '0', 4 ) : " << mem_set( s + 1, '0', 4 )
      << "\n\n s : " << s << endl;

   return EXIT_SUCCESS;
}

void* mem_cpy( void* s1, const void* s2, size_t n ) {
   char* dst{ ( char* )s1 };
   const char* src{ ( const char* )s2 };
   while ( n-- )
      *dst++ = *src++;
   return s1;
}

void* mem_move( void* s1, const void* s2, size_t n ) {
   char* dst{ ( char* )s1 };
   const char* src{ ( const char* )s2 };
   char* tmp{ new char[ n ] };
   for ( size_t i{}; i < n; ++i )
      tmp[ i ] = dst[ i ];
   while ( n-- )
      *dst++ = *src++;
   delete[] tmp;
   return s1;
}

int mem_cmp( const void* s1, const void* s2, size_t n ) {
   const char* p1{ ( const char* )s1 };
   const char* p2{ ( const char* )s2 };
   while ( n-- )
      if ( *p1 > *p2 )
         return 1;
      else if ( *p1++ < *p2++ )
         return -1;
   return 0;
}

void* mem_chr( const void* s, int c, size_t n ) {
   auto pb{ ( const unsigned char* )s }, pe{ pb + n };
   do if ( *pb == ( unsigned char )c )
      return ( void* )pb;
   while ( ++pb < pe );
   return 0;
}

void* mem_set( void* s, int c, size_t n ) {
   auto pb{ ( unsigned char* )s }, pe{ pb + n };
   while ( pb < pe )
      *pb++ = ( unsigned char )c;
   return s;
}
