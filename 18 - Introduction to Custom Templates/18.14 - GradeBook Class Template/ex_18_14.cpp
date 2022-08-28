// Exercise 18.14: ex_18_14.cpp
// GradeBook Class Template

#include <random>
#include "GradeBook.h"
using namespace std;

int main() {

   default_random_engine generator{ random_device{}() };
   uniform_int_distribution< int > number( 42, 100 );

   const size_t TESTS{ 5 }, STUDENTS{ 30 };
   array< array< int, TESTS >, STUDENTS > grades{};
   for ( auto& student : grades )
      for ( auto& grade : student )
         grade = number( generator );

   GradeBook< STUDENTS, TESTS >
      myGradeBook( "CS101 Introduction to C++ Programming", grades );
   myGradeBook.displayMessage();
   myGradeBook.processGrades();

   return EXIT_SUCCESS;
}
