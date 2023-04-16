#include <SCServo.h>

// FEETECH SCS0009 シリアルバスサーボ 4~7.4V/300°/2.3kg
// サーボを基準角度まで回転させる。
//「Goal」の値を511にして「Set」します
// board: M5Stack Core + stack-chan board
// GPIO16 RXD2
// GPIO17 TXD2

SCSCL sc;

void setup()
{
  Serial1.begin(1000000, SERIAL_8N1, 16, 17); // BAUD, SERIAL_8N1, RXPIN, TXPIN
  sc.pSerial = &Serial1;
  delay(1000);

  sc.WritePos(1, 511, 0, 1500);
  sc.WritePos(2, 511, 0, 1500);
}

void loop()
{

}
