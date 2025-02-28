#ifndef __CAN_H
#define __CAN_H

#include <ESP32-TWAI-CAN.hpp>

class CAN {
public:
    CAN(const int txPin, const int rxPin, const int baudRate);
    bool begin();
    bool sendMessage(uint32_t id, uint8_t length, uint8_t* data, bool extended);
private:
    int _txPin;
    int _rxPin;
    int _baudRate;
};

#endif
