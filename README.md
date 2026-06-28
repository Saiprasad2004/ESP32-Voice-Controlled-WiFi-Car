# ESP32 Voice Controlled Wi-Fi Car 🚗🎙️

## Overview

This project demonstrates a Voice Controlled Wi-Fi Car using the ESP32 microcontroller. The ESP32 creates its own Wi-Fi hotspot and hosts a web server that allows users to control the car through a smartphone browser.

The car supports both:

* Manual control using on-screen buttons.
* Voice control using speech recognition in a web browser.

## Features

* Wi-Fi based control using ESP32 Access Point mode.
* Voice commands using browser speech recognition.
* Manual control through web interface buttons.
* Forward, Backward, Left, Right and Stop movements.
* No dedicated mobile application required.
* Real-time wireless control through any smartphone browser.

## Hardware Components

* ESP32 Development Board
* L298N Motor Driver Module
* DC Geared Motors (2)
* Robot Chassis
* Wheels
* Battery Pack
* Jumper Wires
* Smartphone/Laptop

## Software Requirements

* Arduino IDE
* ESP32 Board Package
* Google Chrome Browser
* GitHub Pages (for secure HTTPS voice interface)

## Voice Commands Supported

* "Forward"
* "Backward"
* "Left"
* "Right"
* "Stop"

## Working Principle

1. ESP32 creates a Wi-Fi hotspot.
2. User connects smartphone to the ESP32 network.
3. The web page is opened in a browser.
4. User controls the robot using buttons or voice commands.
5. Commands are sent to ESP32 through HTTP requests.
6. ESP32 drives the motors accordingly.

## Future Improvements

* Speed control slider
* Obstacle avoidance
* Live camera streaming
* Autonomous navigation
* Mobile application integration

## Author

Pasupula Sai Prasad
B.Tech Electronics and Communication Engineering (ECE)
