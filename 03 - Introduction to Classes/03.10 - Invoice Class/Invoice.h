// Exercise 3.10: Invoice.h

#include <string>

class Invoice {

public:

   Invoice( std::string pn, std::string pd, int qnt, int prc ) :
      vat{ 0.2 },
      discount{ 0.0 } {
      setPartNumber( pn );
      setPartDescription( pd );
      setQuantity( qnt );
      setItemPrice( prc );
   }

   void setPartNumber( std::string pn ) {
      partNumber = pn;
   }

   void setPartDescription( std::string pd ) {
      partDescription = pd;
   }

   void setQuantity( int qnt ) {
      if ( qnt < 0 ) quantity = 0;
      if ( qnt >= 0 ) quantity = qnt;
   }

   void setItemPrice( int prc ) {
      if ( prc < 0 ) itemPrice = 0;
      if ( prc >= 0 ) itemPrice = prc;
   }

   void setVAT( double tax ) {
      if ( tax < 0 ) vat = 0.0;
      if ( tax >= 0 ) vat = tax;
   }

   void setDiscount( double dsc ) {
      if ( dsc < 0 ) discount = 0.0;
      if ( dsc >= 0 ) discount = dsc;
   }

   std::string getPartNumber() const {
      return partNumber;
   }

   std::string getPartDescription() const {
      return partDescription;
   }

   int getQuantity() const {
      return quantity;
   }

   int getItemPrice() const {
      return itemPrice;
   }

   double getVAT() const {
      return vat;
   }

   double getDiscount() const {
      return discount;
   }

   double getInvoiceAmount() const {
      return quantity * itemPrice * ( 1.0 - vat - discount );
   }

private:

   std::string partNumber;
   std::string partDescription;
   int quantity;
   int itemPrice;
   double vat;
   double discount;
};
