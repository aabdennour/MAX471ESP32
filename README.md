# MAX471 ESP32 Library

## Table of Contents

- [Overview](#overview)
- [Installation](#installation)
- [Hardware](#hardware)
- [Features](#features)
- [Files](#files)

## Overview

- **Name**: MAX471 ESP32
- **Title**: library for MAX471 voltage and current sensor for the ESP32.
- **Description**:
  - Current reading: 0-3 A
  - Voltage reading: 3-25 V
- **Author**: Abdennour Siouane
- **Arduino IDE**: 2.3.2

## Installation

[Installing Additional Arduino Libraries guide](https://github.com/aabdennour/MAX471ESP32)

## Hardware

Tested with this module.

![MAX471 Module](https://github.com/aabdennour/MAX471ESP32/blob/main/info/MAX471.jpg)

Connect two ADC pins for voltage = VT & current = AT. 
Connect Vout(+RS) to PSU.
Connect Vin(-RS) to the circuit/device under test.


## Files

| Src Files        | Description             |
| ---------------- | ----------------------- |
| `MAX471ESP32.h`       | Library header file     |
| `MAX471ESP32.cpp`     | Library source file     |
| `MAX471ESP32_BASIC` | Example file       |
