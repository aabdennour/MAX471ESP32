/*
* Project Name: MAX471ESP32 ABDENNOUR SIOUANE
* File: MAX471ESP32_BASIC.ino
* Description: Library for MAX471 example file adapted for ESP32
* Tested: on ESP32
* URL: https://github.com/aabdennour/
*/

//******************** LIBRARIES ******************
#include "MAX471ESP32.h"

//******************** GLOBALS + DEFINES **********
// Max471 test parameters
#define TEST_DELAY delay(2000);
#define VT_PIN 34  // Use GPIO 34 for voltage reading (input only)
#define AT_PIN 35  // Use GPIO 35 for current reading (input only)

// Example configurations for ESP32
MAX471 myMax471(ADC_12_bit, VCC_3_3, AT_PIN, VT_PIN);  // 12-bit ADC and 3.3V reference

//******************** SETUP *********************
void setup() {
  Serial.begin(115200); // Adjusted baud rate for ESP32
  Serial.println("== START LIBRARY TEST ==");
}

//******************* MAIN LOOP *****************
void loop() {
  // Test 1: Read Amps and Volts
  Serial.print("A: ");
  Serial.println(myMax471.CurrentRead(), 3);  // Amps with three decimal places
  Serial.print("V: ");
  Serial.println(myMax471.VoltageRead(), 3);  // Volts with three decimal places
  Serial.println();
  TEST_DELAY

  // Test 2: Read mA and mV
  Serial.print("mA: ");
  Serial.println(myMax471.CurrentRead() * 1000, 1);  // Milliamps with one decimal place
  Serial.print("mV: ");
  Serial.println(myMax471.VoltageRead() * 1000, 1);  // Millivolts with one decimal place
  Serial.println();
  TEST_DELAY
} // End of main

