// Exercise 12.14: PieceWorker.cpp

#include <iomanip>
#include <sstream>
#include <string>

#include "PieceWorker.h"

using namespace std;

PieceWorker::PieceWorker( const string& first, const string& last,
                          const string& ssn, int month, int day, int year,
                          double w, unsigned p )
   : Employee{ first, last, ssn, month, day, year },
     wage{ w > 0.0 ? w : throw "Incorrect wage" }, pieces{ p } {
}

double PieceWorker::getWage() const {
   return wage;
}

unsigned PieceWorker::getPieces() const {
   return pieces;
}

double PieceWorker::earnings() const {
   return getWage() * getPieces();
}

string PieceWorker::toString() const {

   ostringstream output;

   output << fixed << setprecision( 2 )
      << "piece worker: " << Employee::toString()
      << "\npieces of merchandise produced: " << getPieces()
      << "; wage per piece: " << getWage();

   return output.str();
}