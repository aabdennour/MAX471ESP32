/*
* Project Name: MAX471ESP32
* File: MAX471ESP32.h
* Description: ESP32 compatible library for MAX471 sensor
* URL: https://github.com/aabdennour/MAX471ESP32
*/

#ifndef MAX471_H
#define MAX471_H

#include "Arduino.h"

// Voltage reference for ADC, in mV
enum VCC_REF_t {
    VCC_3_3 = 3300,
    VCC_5 = 5000,
};

// ESP32 default ADC resolution in bits (12 bits)
enum ADC_RES_t {
    ADC_12_bit = 4096,
};

// Resistor divider network on RS Vo * value
#define RS_VOLT_DIVIDE 5

class MAX471 {
  public:
    MAX471(ADC_RES_t adc, VCC_REF_t vcc, int8_t ATreadPin, int8_t VTreadPin);
    ~MAX471() {};

    float VoltageRead();
    float CurrentRead();

  private:
    float CalcResolution();

    uint16_t _VCC_TYPE;
    uint32_t _ADC_RESOLUTION;
    int8_t _CURRENT_PIN;
    int8_t _VOLTAGE_PIN;
};

#endif // Header Guard EOF
