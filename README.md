# CafePlugGuardian-Hardware

## CafePlugGuardian Project
### Introduction
CafePlugGuardian is a capstone design project at the Chung-Ang University's Department of Software Engineering.

The goal of CafePlugGuardian project is to prevent excessive electricity use by certain customers by giving cafe customers an amount of electricity proportional to their purchase volume, prevent customers from staying in the cafe for long periods of time

And analyze current patterns to charge other devices such as smartphones and laptops allowed in the cafe. Products are automatically blocked.

Please note that we will not be accepting contributions for CafePlugGuardian, as it is a Capstone Design Project.

### Sub Projects of CafePlugGuardian
* [CafePlugGuardian-Client](https://github.com/CAU-Capstone-PPL/CafePlugGuardian-Client)
    * Cafe Manager App - flutter app
* [CafePlugGuardian-WebClient](https://github.com/CAU-Capstone-PPL/CafePlugGuardian-WebClient)
    * Cafe Customer Web - flutter web
* [CafePlugGuardian-Server](https://github.com/CAU-Capstone-PPL/CafePlugGuardian-Server)
    * Backend server - typescript, node.js, express.js, mqtt
* [CafePlugGuardian-ML_Server_Flask](https://github.com/CAU-Capstone-PPL/CafePlugGuardian-ML_Server_Flask)
    * AI server - flask
* [CafePlugGuardian-Hardware](https://github.com/CAU-Capstone-PPL/CafePlugGuardian-Hardware)
    * SmartPlug embedded system - arduino(tasmota open source)

## CafePlugGuardian-Hardware
### Introduction
CafePlugGuardian-Hardware is a part of CafePlugGuardian project.

The goal of CafePlugGuardian-Hardware project is to measure household alternating current and sample the wattage and current patterns of used home appliances.

It was constructed based on esp32 and used an ACS712 current sensor and a Zmpt101b voltage sensor.

Power is measured at 1 second intervals and transmitted to the backend through the tasmota rule, and the current pattern is measured 500 times at 0.5ms intervals and transmitted when a request is received from the backend.

### Tasmota Open Source
Our project heavily relies on Tasmota as the base firmware.

Tasmota is an open-source firmware that provides a web interface, MQTT support, and a wide range of device support for home automation.

For more in-depth information on Tasmota and its functionalities, it's recommended to explore the official Tasmota GitHub repository: [Tasmota GitHub Repository](https://github.com/arendst/Tasmota)

### How to use CafePlugGuardian-Hardware
* Require Hardware
    * esp32
        * main micro control unit
        * In our project, we used the lolin d32 pro development board, but it doesn't matter as long as it is an esp32.
        * To use the esp8266, you need to modify the code, and since there is only one ADC, analog measurement of voltage is impossible, so you need to find another method.
    * ACS712
        * current sensor
        * There are 5A, 20A, and 30A models. Use the appropriate model.
        * In our project, the current of the measurement target is generally less than 1A, so we used the 5A model.
    * Zmpt101b
        * voltage sensor
    * Resistance
    * Capacitor


## License
This program is licensed under GPL-3.0