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
#define TEST_DELAY 2000  // Delay in milliseconds, adjust as needed for your application
#define VT_PIN 34        // Use GPIO 34 for voltage reading (input only)
#define AT_PIN 35        // Use GPIO 35 for current reading (input only)

// Example configurations for ESP32
MAX471 myMax471(ADC_12_bit, VCC_3_3, AT_PIN, VT_PIN);  // 12-bit ADC and 3.3V reference
float accumulatedEnergy = 0.0;                         // To store accumulated energy in watt-hours

//******************** SETUP *********************
void setup() {
  Serial.begin(115200);  // Start serial communication at 115200 baud
  Serial.println("MAX471 Sensor Test Initialized");
}

//******************* MAIN LOOP *****************
void loop() {
  float current = myMax471.CurrentRead();                 // Read current in Amps
  float voltage = myMax471.VoltageRead();                 // Read voltage in Volts
  float power = current * voltage;                        // Calculate power in Watts
  accumulatedEnergy += power * (TEST_DELAY / 3600000.0);  // Accumulate energy in Wh, converting time from ms to hours

  // Output the measurements
  Serial.print("Current (A): ");
  Serial.println(current, 3);

  Serial.print("Voltage (V): ");
  Serial.println(voltage, 3);

  Serial.print("Power (W): ");
  Serial.println(power, 3);
  
  Serial.print("Accumulated Energy (Wh): ");
  Serial.println(accumulatedEnergy, 3);
  Serial.println();  // Blank line for better readability

  delay(TEST_DELAY);  // Wait for a specified time delay before the next measurement
}
