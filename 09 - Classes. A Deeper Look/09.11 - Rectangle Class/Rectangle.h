// Exercise 9.11: Rectangle.h
// Member functions defined in Rectangle.cpp

#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {

public:

   explicit Rectangle( float = 1.0, float = 1.0 );

   void setLength( float );
   void setWidth( float );

   const float getLength() const;
   const float getWidth() const;

   const float perimeter() const;
   const float area() const;

private:

   float length{ 1.0 };
   float width{ 1.0 };
};

#endif