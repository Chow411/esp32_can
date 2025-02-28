#include "CAN.h"

CAN::CAN(const int txPin, const int rxPin, const int baudRate){
    _txPin = txPin;
    _rxPin = rxPin;
    _baudRate = baudRate;
}


bool CAN::begin(){
    ESP32Can.setPins(_txPin, _rxPin);
    ESP32Can.setSpeed(ESP32Can.convertSpeed(_baudRate));
    return ESP32Can.begin();
}

bool CAN::sendMessage(uint32_t id, uint8_t length, uint8_t* data, bool extended) {
    CanFrame frame;
    frame.identifier = id;
    frame.extd = extended;
    frame.data_length_code = length;

    for (int i = 0; i < length && i < 8; i++) {
        frame.data[i] = data[i];
    }

    if (ESP32Can.writeFrame(frame)) return true;
    else return false;
}