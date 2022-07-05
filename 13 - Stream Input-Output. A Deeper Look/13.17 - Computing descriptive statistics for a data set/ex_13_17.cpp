// Exercise 13.17: ex_13_17.cpp
// Computing descriptive statistics for a data set

#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

inline double mean( const vector< double >& );
inline double median( const vector< double >& );
inline double sd( const vector< double >& );
inline double min( const vector< double >& );
inline double max( const vector< double >& );

int main() {

   cout << fixed << setprecision( 2 ) << "Numbers + EOF: ";

   double number;
   vector< double > numbers;

   while ( cin >> number )
      numbers.push_back( number );

   if ( numbers.empty() ) {
      cerr << "ERROR: no data" << endl;
      exit( 1 );
   }

   cout << "\nMean is " << mean( numbers )
      << "\nMedian is " << median( numbers )
      << "\nStandard deviation is " << sd( numbers )
      << "\nMinimum is " << min( numbers )
      << "\nMaximum is " << max( numbers ) << endl;

   return 0;
}

double mean( const vector< double >& VEC ) {
   double sum{};
   for ( auto& element : VEC )
      sum += element;
   return sum / VEC.size();
}

double median( const vector< double >& VEC ) {
   size_t i{ VEC.size() / 2 };
   return VEC.size() % 2 ? VEC[ i ] : ( VEC[ i - 1 ] + VEC[ i ] ) / 2;
}

double sd( const vector< double >& VEC ) {
   double sum{};
   const double MEAN{ mean( VEC ) };
   for ( auto& element : VEC )
      sum += pow( element - MEAN, 2 );
   return sqrt( sum / VEC.size() ); // population value
}

double min( const vector< double >& VEC ) {
   double min{ VEC[ 0 ] };
   for ( auto& element : VEC )
      if ( element < min )
         min = element;
   return min;
}

double max( const vector< double >& VEC ) {
   double max{ VEC[ 0 ] };
   for ( auto& element : VEC )
      if ( element > max )
         max = element;
   return max;
}
