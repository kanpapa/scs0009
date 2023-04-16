#include <SCServo.h>

// FEETECH SCS0009 シリアルバスサーボ 4~7.4V/300°/2.3kg
// test program 1 
// board: M5Stack Core + stack-chan board
// GPIO16 RXD2
// GPIO17 TXD2

SCSCL sc;

void setup()
{
  Serial1.begin(1000000, SERIAL_8N1, 16, 17); // BAUD, SERIAL_8N1, RXPIN, TXPIN
  sc.pSerial = &Serial1;
  delay(1000);
}

void loop()
{
  sc.WritePos(1, 1000, 0, 1500);
  delay(754);  //[(P1-P0)/V]*1000+[V/(A*100)]*1000

  sc.WritePos(1, 20, 0, 1500);
  delay(754);  //[(P1-P0)/V]*1000+[V/(A*100)]*1000
}
