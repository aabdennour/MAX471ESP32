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
#define TEST_DELAY 2000  // Delay in milliseconds
#define VT_PIN 34        // Use GPIO 34 for voltage reading (input only)
#define AT_PIN 35        // Use GPIO 35 for current reading (input only)

// Example configurations for ESP32
MAX471 myMax471(ADC_12_bit, VCC_3_3, AT_PIN, VT_PIN);  // 12-bit ADC and 3.3V reference
float accumulatedEnergy_mWh = 0.0;                     // To store accumulated energy in milliwatt-hours
float accumulatedEnergy_J = 0.0;                       // To store accumulated energy in Joules

//******************** SETUP *********************
void setup() {
  Serial.begin(115200);  // Start serial communication at 115200 baud
  Serial.println("MAX471 Sensor Test Initialized");
}

//******************* MAIN LOOP *****************
void loop() {
  float current = myMax471.CurrentRead();  // Read current in Amps
  float voltage = myMax471.VoltageRead();  // Read voltage in Volts
  float power = current * voltage;         // Calculate power in Watts

  // Convert all readings to milli units
  float current_mA = current * 1000;  // Convert to milliamperes
  float voltage_mV = voltage * 1000;  // Convert to millivolts
  float power_mW = power * 1000;      // Convert to milliwatts

  // Calculate energy in milliwatt-hours and Joules
  accumulatedEnergy_mWh += power_mW * (TEST_DELAY / 3600000.0);  // Convert ms to hours
  accumulatedEnergy_J += power * (TEST_DELAY / 1000.0);          // Convert ms to seconds for Joules (1 Watt = 1 Joule per second)

  // Output the measurements
  Serial.print("Current (mA): ");
  Serial.println(current_mA, 1);

  Serial.print("Voltage (mV): ");
  Serial.println(voltage_mV, 1);

  Serial.print("Power (mW): ");
  Serial.println(power_mW, 1);

  Serial.print("Accumulated Energy (mWh): ");
  Serial.println(accumulatedEnergy_mWh, 3);
  
  Serial.print("Accumulated Energy (J): ");
  Serial.println(accumulatedEnergy_J, 3);
  Serial.println();  // Blank line for better readability

  delay(TEST_DELAY);  // Wait for a specified time delay before the next measurement
}
