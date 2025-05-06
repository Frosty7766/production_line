# Automated Mechatronic Production Line

This project implements an automated production line system using Arduino, consisting of four main components: sorting, assembly, filling, and handling systems. The system integrates mechanical and electrical components to automate product handling and packaging operations, guided by precise motion control and sensor feedback.

## Project Information
- **Courses**: 
  - SET323: Real-Time and Embedded Systems Design
  - MCT 324: Embedded System Design
- **University**: Egyptian Chinese University
- **Departments**: 
  - Department of Mechatronics, Level 3
  - Department of Software Engineering, Level 3
- **Supervisor**: Dr. Ahmed Othman
- **Teaching Assistants**: 
  - Eng. Hagar Rabea
  - Nour Mandour

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
- 6-degree-of-freedom (6 DOF) robotic arm
- Each joint actuated by a servo motor for precise, multi-axis movement
- IR sensors for height detection and product sorting
- Components:
  - Servo motors (5x)
  - IR sensors (2x)
  - Arduino board
  - Nema 17 Stepper Motor
  - A4988 Stepper Motor Driver
  - Micro Vacuum Pump
  - L297D Driver (for pump control)

### 2. Assembly System (assembly.ino)
- Vertical (Z) axis assembly/disassembly operations
- Precise cap placement and removal
- Components:
  - Nema 17 Stepper Motor
  - A4988 Stepper Motor Driver
  - Micro Vacuum Pump
  - L297D Driver (for pump control)
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

### 4. Handling System (handling.ino)
- Dual stepper motor control for product movement
- IR sensors for start and stop detection
- Synchronized motor movement
- Components:
  - Stepper motors (2x)
  - IR sensors (2x)
  - Arduino board

## Operation Sequence
1. Products are placed on the upper conveyor
2. IR sensors detect product height and signal the robotic arm
3. Robotic arm sorts products to designated locations
4. Sorted products move to assembly station
5. Stepper-motor-driven suction system handles cap placement/removal
6. Products proceed to filling station
7. Handling system manages product movement between stations

## Hardware Requirements
- Arduino boards (4x)
- Servo motors (5x)
- Stepper motors (3x)
- Air pump
- Water pump
- Flow meter (YF-S401)
- IR sensors (6x)
- L293N motor driver
- A4988 Stepper Motor Drivers
- L297D Drivers
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

### Handling System
- Motor 1: Pins 2, 3
- Motor 2: Pins 4, 5
- IR Sensors: Pins 6, 7

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
   - Handle product movement between stations

## Safety Considerations
- Ensure proper power supply
- Check all connections before operation
- Monitor system during operation
- Follow proper shutdown procedures 