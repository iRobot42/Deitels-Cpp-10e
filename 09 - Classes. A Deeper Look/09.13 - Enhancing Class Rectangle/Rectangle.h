// Exercise 9.13: Rectangle.h
// Member functions defined in Rectangle.cpp

#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {

public:

   Rectangle(); // default constructor
   explicit Rectangle( const float*, const float*, const float*, const float*,
                       const char, const char );

   void setPoints( const float*, const float*, const float*, const float* );
   void setPerimeterCharacter( const char );
   void setFillCharacter( const char );
   void scale( const float );
   void move( const float, const float );

   float length() const;
   float width() const;
   float perimeter() const;
   float area() const;

   bool square() const;

   void print() const;
   void draw() const;

private:

   const float ML{ 20.0 }; // max length
   const float QS{ 25.0 }; // visible quadrant size

   float a[ 2 ]{}; // bottom left
   float b[ 2 ]{}; // bottom right
   float c[ 2 ]{}; // top left
   float d[ 2 ]{}; // top right

   char fc{ '~' }; // fill character
   char pc{ 'o' }; // perimeter character

   float dx{}; // offset x
   float dy{}; // offset y
};

#endif