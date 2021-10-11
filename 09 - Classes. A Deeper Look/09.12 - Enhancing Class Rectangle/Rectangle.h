// Exercise 9.12: Rectangle.h
// Member functions defined in Rectangle.cpp

#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {

public:

   Rectangle(); // default constructor
   explicit Rectangle( const float*, const float*, const float*, const float* );

   void setPoints( const float*, const float*, const float*, const float* );

   float length() const;
   float width() const;
   float perimeter() const;
   float area() const;

   bool square() const;
   void print() const; // test

private:

   float a[ 2 ]{};
   float b[ 2 ]{};
   float c[ 2 ]{};
   float d[ 2 ]{};
};

#endif