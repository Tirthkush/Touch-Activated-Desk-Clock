# Touch-Activated Desk Clock

## Overview

This project is a battery-powered touch-activated desk clock built using an Arduino Nano, DS3231 RTC module, and a 16×2 LCD display.

Unlike conventional clocks that continuously consume power, this design utilizes the AVR sleep mode to minimize power consumption. The system remains in low-power sleep mode until the touch sensor is activated. Once touched, the Arduino wakes instantly, reads the current date, time, and temperature from the DS3231 RTC module, displays the information for 5 seconds, and automatically returns to sleep.

The project focuses on embedded systems, low-power design, real-time clock interfacing, battery management, and practical hardware integration.

---

# Features

- Touch-activated wake-up
- AVR Sleep Mode for low power consumption
- Displays Date
- Displays Time
- Displays Temperature (DS3231 internal sensor)
- Automatic return to sleep after 5 seconds
- Battery-powered operation
- Backup RTC battery for accurate timekeeping

---

# Hardware Used

- Arduino Nano
- DS3231 RTC Module
- 16×2 LCD Display
- Capacitive Touch Sensor
- 18650 Li-ion Battery
- TP4056 Charging Module
- TPS61023 Boost Converter
- CR2032 Backup Coin Cell
- Breadboard / Prototype Wiring
- Connecting Wires

---

# System Architecture

## Arduino Nano

The Arduino Nano serves as the main controller responsible for:

- Managing sleep and wake-up operations
- Reading RTC data
- Updating the LCD display
- Controlling overall system operation

---

## DS3231 RTC Module

The DS3231 provides:

- Accurate Date
- Accurate Time
- Built-in Temperature Sensor
- Battery-backed Timekeeping

A CR2032 coin cell ensures that the RTC continues keeping accurate time even when the main battery is disconnected.

---

## Touch Sensor

The touch sensor acts as the wake-up trigger.

When touched:

- Arduino exits sleep mode
- LCD powers on
- Current date, time, and temperature are displayed
- System automatically returns to sleep after 5 seconds

---

# Working Principle

1. Arduino enters AVR Sleep Mode.
2. Touch sensor generates an interrupt.
3. Arduino wakes instantly.
4. Current date, time, and temperature are read from the DS3231.
5. Information is displayed on the LCD.
6. After 5 seconds, the display turns off.
7. Arduino returns to sleep mode.

This significantly reduces overall power consumption compared to keeping the display continuously active.

---

# Power Architecture

The system is powered using a rechargeable 18650 Li-ion battery.

18650 Battery
↓
TP4056 Charging Module
↓
TPS61023 Boost Converter (5V)
↓
Arduino Nano + LCD + RTC

The TP4056 provides battery charging and protection, while the TPS61023 boosts the battery voltage to provide a stable 5V supply for the Arduino Nano and peripherals.
The DS3231 contains a dedicated CR2032 backup battery, allowing it to maintain accurate time even when the main battery is removed.

---

# Low Power Design

Instead of continuously updating the display, the project utilizes the AVR sleep library.
Benefits include:

- Reduced battery consumption
- Longer battery life
- Instant wake-up using interrupt
- Efficient embedded system design

---

# Challenges Encountered

## Power Management
Designing a battery-powered system required proper voltage regulation to ensure stable operation.

## Sleep Mode Implementation
Implementing AVR sleep mode while maintaining instant responsiveness through the touch sensor required interrupt-based programming.

## RTC Integration
Interfacing the DS3231 for accurate date, time, and temperature readings while preserving backup functionality.

## Hardware Integration
Managing multiple modules within a compact breadboard prototype while ensuring reliable operation.

---

# Results

The project successfully demonstrates a low-power touch-activated desk clock capable of displaying accurate date, time, and temperature while maximizing battery life through sleep mode.
The system operates reliably on a rechargeable battery and showcases practical embedded systems design concepts.

---

# Key Learnings

- AVR Sleep Modes
- Interrupt Handling
- DS3231 RTC Interfacing
- I2C Communication
- Battery Power Management
- Voltage Regulation
- Low-Power Embedded System Design
- Hardware Debugging and Integration

---

# Future Improvements

- Custom PCB Design
- 3D Printed Enclosure
- OLED/TFT Display Upgrade
- Battery Percentage Indicator
- Alarm Functionality
- Automatic Brightness Control
- USB-C Charging
- ESP32-based IoT Version with NTP Time Synchronization

---

# Applications

- Smart Desk Clock
- Low-Power Embedded Systems
- Educational Projects
- Battery-Powered Electronics
- Embedded Systems Learning
- IoT Clock Development

---

# Author

**Tirth Kushwaha**

Electronics & Telecommunication Engineering

Embedded Systems | IoT | Robotics | PCB Design
