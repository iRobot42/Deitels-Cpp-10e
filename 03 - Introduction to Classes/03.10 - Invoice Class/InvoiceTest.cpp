// Exercise 3.10: InvoiceTest.cpp

#include <iostream>
#include "Invoice.h"

using namespace std;

int main() {

   Invoice invoice( "A-1", "Description", 100, -42 );

   cout << "INITIAL INVOICE"
      << "\nPart number:      " << invoice.getPartNumber()
      << "\nPart description: " << invoice.getPartDescription()
      << "\nQuantity:         " << invoice.getQuantity()
      << "\nItem price:       " << invoice.getItemPrice()
      << "\nVAT rate:         " << invoice.getVAT()
      << "\nDiscount rate:    " << invoice.getDiscount()
      << "\nInvoice amount:   " << invoice.getInvoiceAmount()
      << endl;

   invoice.setPartNumber( "A-1m" );
   invoice.setPartDescription( "Modified description" );
   invoice.setQuantity( 10 );
   invoice.setItemPrice( 42 );
   invoice.setVAT( 0.15 );
   invoice.setDiscount( 0.05 );

   cout << "\nMODIFIED INVOICE"
      << "\nPart number:      " << invoice.getPartNumber()
      << "\nPart description: " << invoice.getPartDescription()
      << "\nQuantity:         " << invoice.getQuantity()
      << "\nItem price:       " << invoice.getItemPrice()
      << "\nVAT rate:         " << invoice.getVAT()
      << "\nDiscount rate:    " << invoice.getDiscount()
      << "\nInvoice amount:   " << invoice.getInvoiceAmount()
      << endl;

   return 0;
}
