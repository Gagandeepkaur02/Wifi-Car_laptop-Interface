# Wifi-Car_laptop-Interface
# ESP8266 WiFi Controlled 2WD Robot Car

A simple WiFi-controlled 2WD robot car built using an ESP8266 NodeMCU, L298N motor driver, and BO motors. The robot hosts a web-based control interface that allows users to control the car from any device connected to the same WiFi network.

## Features

* WiFi-based robot control
* Web interface accessible through any browser
* Forward movement
* Backward movement
* Left turn
* Right turn
* Stop function
* Adjustable motor speed using PWM
* Built using ESP8266 and L298N motor driver

## Hardware Requirements

* ESP8266 NodeMCU
* L298N Motor Driver Module
* 2 × BO Motors
* Robot Chassis
* Wheels
* Battery Pack
* Jumper Wires

## Circuit Connections

| ESP8266 NodeMCU | L298N |
| --------------- | ----- |
| D5              | ENA   |
| D6              | ENB   |
| D8              | IN1   |
| D7              | IN2   |
| D4              | IN3   |
| D3              | IN4   |
| GND             | GND   |

## Motor Logic

### Forward

* Left Motor: Forward
* Right Motor: Forward

### Backward

* Left Motor: Reverse
* Right Motor: Reverse

### Left Turn

* Left Motor: Reverse
* Right Motor: Reverse

### Right Turn

* Left Motor: Forward
* Right Motor: Forward

Motor directions were adjusted according to the physical wiring of the motors.

## Software Requirements

* Arduino IDE
* ESP8266 Board Package
* ESP8266WiFi Library

## Installing ESP8266 Board Package

Open Arduino IDE and add the following URL in:

File → Preferences → Additional Boards Manager URLs

http://arduino.esp8266.com/stable/package_esp8266com_index.json

Then:

1. Open Boards Manager
2. Search for ESP8266
3. Install ESP8266 by ESP8266 Community

## WiFi Configuration

Update the following lines in the code:

```cpp
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";
```

## Uploading the Code

1. Connect NodeMCU via USB.
2. Select the correct COM Port.
3. Select NodeMCU 1.0 (ESP-12E Module).
4. Upload the code.
5. Open Serial Monitor at 115200 baud.

## Accessing the Robot

After connecting to WiFi, the Serial Monitor will display an IP address:

```text
WiFi Connected
IP Address: 192.168.x.x
```

Open this IP address in a browser:

```text
http://192.168.x.x
```

## Web Controls

The web interface provides:

* FORWARD
* BACKWARD
* LEFT
* RIGHT
* STOP

## Project Structure

```text
ESP8266-WiFi-Robot-Car/
│
├── RobotCar.ino
├── README.md
├── circuit_diagram.png
├── robot_image.jpg
└── LICENSE
```

## Future Improvements

* Speed Control Slider
* Joystick Interface
* Autonomous Mode
* Obstacle Avoidance
* Line Following
* Mobile Responsive UI
* OTA Updates

## Author
Gagandeepkaur Saluja

Electronics, Robotics, STEM Education and Embedded Systems

## License

This project is released under the MIT License.
