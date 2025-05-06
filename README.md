# Production Line Automation System

This project implements an automated production line system using Arduino, consisting of three main components: sorting, assembly, and filling systems.

## Team Members
- Jomana Mohamed (192100086)
- Khaled Hesham (192100074)
- Abdelrahman Haitham (192100002)
- Lojine Ehab (192100003)
- Liza Tharwat (192100018)
- Mohanad Yasser (192100147)
- Omnia Tamer (192100081)
- Mohamed Ahmed (192100046)
- Shehab Mohamed (192100097)
- Ahmed Shawky (192100096)

## System Components

### 1. Sorting System (sorting_robot.ino)
- Uses 5 servo motors for precise arm movement
- Implements 2 IR sensors for object detection
- Features three positions: lower, upper, and default
- Components:
  - Servo motors (5x)
  - IR sensors (2x)
  - Arduino board

### 2. Assembly System (assembly.ino)
- Implements stepper motor control for precise movement
- Features air pump for item handling
- Components:
  - Stepper motor
  - Air pump
  - IR sensor
  - Arduino board

### 3. Filling System (filling.ino)
- Precise liquid filling with flow meter
- Valve control using L293N motor driver
- Target volume: 200ml
- Components:
  - Flow meter (YF-S401)
  - Water pump
  - L293N motor driver
  - IR sensor
  - Arduino board

## Hardware Requirements
- Arduino boards (3x)
- Servo motors (5x)
- Stepper motor
- Air pump
- Water pump
- Flow meter (YF-S401)
- IR sensors (4x)
- L293N motor driver
- Power supply
- Various connecting wires and components

## Software Requirements
- Arduino IDE
- Required Libraries:
  - Servo.h (for sorting system)

## Pin Configuration

### Sorting System
- IR Sensors: Pins 7, 8
- Servo Motors: Pins 3, 5, 6, 9, 10

### Assembly System
- IR Sensor: Pin 6
- Stepper Motor: Pins 8, 9
- Air Pump: Pin 5

### Filling System
- IR Sensor: Pin 3
- Pump Control: Pins 8, 9, 10
- Valve Control: Pins 11, 12, 13
- Flow Meter: Pin 2

## Installation
1. Clone this repository
2. Open each .ino file in Arduino IDE
3. Install required libraries
4. Upload each file to its respective Arduino board
5. Connect hardware components according to pin configuration

## Usage
1. Power on the system
2. Place items in the sorting area
3. The system will automatically:
   - Sort items using the robot arm
   - Assemble components using the stepper motor
   - Fill containers with precise liquid volume

## Safety Considerations
- Ensure proper power supply
- Check all connections before operation
- Monitor system during operation
- Follow proper shutdown procedures 