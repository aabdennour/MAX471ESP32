/*
* Project Name: MAX471ESP32
* File: MAX471ESP32.cpp
* Description: ESP32 compatible library source for MAX471 sensor
* URL: [Your new repository URL]
*/

#include "MAX471ESP32.h"

// Constructor for class MAX471
MAX471::MAX471(ADC_RES_t adc, VCC_REF_t vcc, int8_t ATreadPin, int8_t VTreadPin) {
    _ADC_RESOLUTION = adc;
    _VCC_TYPE = vcc;
    _CURRENT_PIN = ATreadPin;
    _VOLTAGE_PIN = VTreadPin;
}

// Reads current on ADC pin
float MAX471::CurrentRead() {
    uint16_t ATread = analogRead(_CURRENT_PIN);
    return (ATread * CalcResolution());
}

// Reads voltage on ADC pin
float MAX471::VoltageRead() {
    uint16_t VTread = analogRead(_VOLTAGE_PIN);
    return ((VTread * CalcResolution()) * RS_VOLT_DIVIDE);
}

// Calculates the resolution per volt
float MAX471::CalcResolution() {
    return (((float)_VCC_TYPE / 1000) / _ADC_RESOLUTION);
}
