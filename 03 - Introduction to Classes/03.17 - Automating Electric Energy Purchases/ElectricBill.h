// Exercise 3.17: ElectricBill.h

class ElectricBill {

public:

   ElectricBill( double ap ) {
      setAmountPaid( ap );
   }

   void setAmountPaid( double ap ) {
      amountPaid = ap;
      if ( ap < 0 )
         amountPaid = 0;
   }

   double getAmountPaid() const {
      return amountPaid;
   }

   double getVAT() const {
      return amountPaid * 0.18;
   }

   double getEWURA() const {
      return amountPaid * 0.01;
   }

   double getREA() const {
      return amountPaid * 0.03;
   }

   double getUnits() const {
      return ( amountPaid - getVAT() - getREA() - getEWURA() - 5000 ) / 295;
   }

private:

   double amountPaid;
};
