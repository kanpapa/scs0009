#include <SCServo.h>

// FEETECH SCS0009 シリアルバスサーボ 4~7.4V/300°/2.3kg
// サーボのIDを２にします。工場出荷時の初期値は ID=1 です。
//   ID1: 足側（左右回転、パン軸）
//   ID2: 顔側（上下回転、チルト軸）
// Board: M5Stack Core + stack-chan board
// GPIO16 RXD2
// GPIO17 TXD2

SCSCL sc;

void setup()
{
  Serial.begin(115200);
  Serial1.begin(1000000, SERIAL_8N1, 16, 17); // BAUD, SERIAL_8N1, RXPIN, TXPIN
  sc.pSerial = &Serial1;
  delay(1000);

//  int param5 = sc.readByte(1, 0);
//  int param6 = sc.readByte(1, 1);
// Serial.println(param5);
//  Serial.println(param6);

  sc.WritePos(1, 1000, 0, 1500);
  delay(800);

  sc.unLockEprom(1);  // ID1のサーボのEPROM書き込みをアンロックする
  delay(100);
  sc.writeByte(1, SCSCL_ID, 2); // サーボIDを2にする
  delay(100);
  sc.LockEprom(2);    //　ID2のサーボのEPROM書き込みをロックする。(この時点でIDが2になっているので2を指定している）
  delay(100);
  
  sc.WritePos(1, 20, 0, 1500);
}

void loop()
{

}
