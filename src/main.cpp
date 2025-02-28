#include <Arduino.h>
#include <CAN.h>

const int CAN_TX = 5;
const int CAN_RX = 4;
const int CAN_BAUDRATE = 500;

CAN can(CAN_TX, CAN_RX,CAN_BAUDRATE);
void setup() {
  Serial.begin(115200);
  if (!can.begin()){
    Serial.println("CAN init failed");
    while (1);
  }
  Serial.println("CAN init success");
}

void loop() {
  uint8_t data[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
  can.sendMessage(0x001, 8, data, false);
  delay(1000);
}