// Exercise 12.14: PieceWorker.h

#ifndef PIECEWORKER_H
#define PIECEWORKER_H

#include "Employee.h"

class PieceWorker : public Employee {

public:

   PieceWorker( const std::string&, const std::string&, const std::string&,
                int, int, int, double, unsigned );
   virtual ~PieceWorker() = default;

   double getWage() const;
   unsigned getPieces() const;

   virtual double earnings() const override;
   virtual std::string toString() const override;

private:

   double wage;
   unsigned pieces;
};

#endif