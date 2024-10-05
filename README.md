# Obstacle Avoidance with Line Following Car

This project demonstrates the development of a robotic car that follows a line and avoids obstacles in its path. It uses an Arduino board, stepper motors, sensors, and various components to achieve the functionality of a smart autonomous robot capable of navigating predefined paths while avoiding collisions.

**Robotic car**: 
![Robot Car](https://github.com/Juwel2121/obstacle-avoidance-with-line-following-car/blob/main/obstacle%20avoid%2C%20line%20follow2.jpg)
## Features
- **Line following**: The car uses IR sensors to detect and follow a predefined path (line).
- **Obstacle avoidance**: The car is equipped with an ultrasonic sensor that detects obstacles and avoids collisions by taking necessary actions.
- **Motor control**: Stepper motors are controlled via motor drivers to enable smooth movement of the car.

## Equipment Used

### Motors and Motor Drivers
- **Stepper Motor**:
  - L298N Stepper Motor Driver Red 
- **Motor Driver**:
  - L298 Motor Driver for controlling the stepper motors.

### Arduino Microcontrollers
- **Arduino Mega R3 2560 **

### Car Chassis and Components
- **2WD Smart Robot Car Kit **: 
  A 2-wheel drive (3-wheel) car chassis kit used as the base of the robot.
  
- **Mini Servo Motor**
- **18650 Battery Holder (2 cells)**
- **18650 Battery Cell (3.7V) x2**
- **IR Sensors x2** for line following
- **Ultrasonic Sensor (HC-SR04)** for obstacle detection 
- **Ultrasonic Sensor Holder**
  
### Tools and Accessories
- **Hot Air Gun**
- **Tester, Screwdriver**
- **Pilus**

## How It Works

1. **Line Following**: The car follows a black line on a white surface using the two IR sensors mounted at the front of the car. The sensors detect the line and send signals to the Arduino, which adjusts the movement of the motors to keep the car aligned with the path.

2. **Obstacle Avoidance**: The ultrasonic sensor detects obstacles in the car's path. When an obstacle is detected, the car will stop or change direction to avoid the collision.

## Installation

To replicate this project, follow these steps:

1. Clone the repository:

   ```bash
   git clone https://github.com/Juwel2121/obstacle-avoidance-with-line-following-car.git
