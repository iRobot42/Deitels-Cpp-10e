// Exercise 18.14: GradeBook.h

#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include <array>
#include <iomanip>
#include <iostream>
#include <string>

template< const size_t STUDENTS, const size_t TESTS >
class GradeBook {

public:

   GradeBook( const std::string& NAME,
              const std::array< std::array< int, TESTS >, STUDENTS >& GRADES )
      : courseName( NAME ), grades( GRADES ) {
   }

   void setCourseName( const std::string& NAME ) {
      courseName = NAME;
   }

   const std::string& getCourseName() const {
      return courseName;
   }

   void displayMessage() const {
      std::cout << "Welcome to the grade book for\n" << getCourseName()
         << '!' << std::endl;
   }

   void processGrades() const {
      outputGrades();
      std::cout << "\nLowest grade in the grade book is " << getMinimum()
         << "\nHighest grade in the grade book is " << getMaximum()
         << std::endl;
      outputBarChart();
   }

   int getMinimum() const {
      int lowGrade{ 100 };
      for ( const auto& STUDENT : grades )
         for ( const auto& GRADE : STUDENT )
            if ( GRADE < lowGrade )
               lowGrade = GRADE;
      return lowGrade;
   }

   int getMaximum() const {
      int highGrade{};
      for ( const auto& STUDENT : grades )
         for ( const auto& GRADE : STUDENT )
            if ( GRADE > highGrade )
               highGrade = GRADE;
      return highGrade;
   }

   double getAverage( const std::array< int, TESTS >& GRADES ) const {
      int total{};
      for ( const int GRADE : GRADES )
         total += GRADE;
      return static_cast< double >( total ) / GRADES.size();
   }

   void outputBarChart() const {

      std::cout << "\nOverall grade distribution:" << std::endl;

      const size_t SIZE{ 11 };
      std::array< unsigned int, SIZE > frequency{};

      for ( const auto& STUDENT : grades )
         for ( const auto& TEST : STUDENT )
            ++frequency[ TEST / 10 ];

      for ( size_t count{}; count < SIZE; ++count ) {
         if ( !count )
            std::cout << "  0-9: ";
         else if ( 10 == count )
            std::cout << "  100: ";
         else
            std::cout << count * 10 << '-' << ( count * 10 ) + 9 << ": ";
         std::cout << std::string( frequency[ count ], '*' ) << std::endl;
      }
   }

   void outputGrades() const {

      std::cout << "\nThe grades are:\n            ";

      for ( size_t test{}; test < TESTS; ++test )
         std::cout << "Test " << test + 1 << "  ";
      std::cout << "Average" << std::endl;

      for ( size_t student{}; student < grades.size(); ++student ) {

         std::cout << "Student " << std::setw( 2 ) << student + 1;

         for ( size_t test{}; test < grades[ student ].size(); ++test )
            std::cout << std::setw( 8 ) << grades[ student ][ test ];

         double average{ getAverage( grades[ student ] ) };
         std::cout << std::setw( 9 ) << std::setprecision( 2 )
            << std::fixed << average << std::endl;
      }
   }

private:

   std::string courseName;
   std::array< std::array< int, TESTS >, STUDENTS > grades;
};

#endif