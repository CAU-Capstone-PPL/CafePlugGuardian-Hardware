# CafePlugGuardian-Hardware

## CafePlugGuardian Project
### Introduction
CafePlugGuardian is a capstone design project at the Chung-Ang University's Department of Software Engineering.

Please note that we will not be accepting contributions for CafePlugGuardian, as it is a Capstone Design Project.

#### The Goal of CafePlugGuardian Project
1. The pin number allows only cafe customers to use the plug, preventing unauthorized use of the plug.
2. Limit the amount of electricity to restrict customers who use excessive power or stay for long periods of time.
3. By analyzing the current patterns of devices in use, devices not permitted in the cafe, such as smartphones and laptop chargers, are automatically blocked through machine learning.

### Structure of CafePlugGuardian
<img width="50%" src="https://github.com/CAU-Capstone-PPL/CafePlugGuardian-Server/assets/55429793/74940115-831a-49f7-ab9a-3d5dc402089a"/>

### Sub Projects of CafePlugGuardian
* [CafePlugGuardian-Client](https://github.com/CAU-Capstone-PPL/CafePlugGuardian-Client)
    * Cafe Manager App - flutter app
* [CafePlugGuardian-WebClient](https://github.com/CAU-Capstone-PPL/CafePlugGuardian-WebClient)
    * Cafe Customer Web - flutter web
* [CafePlugGuardian-Server](https://github.com/CAU-Capstone-PPL/CafePlugGuardian-Server)
    * Backend server - express.js
* [CafePlugGuardian-Hardware](https://github.com/CAU-Capstone-PPL/CafePlugGuardian-Hardware)
    * SmartPlug embedded system - arduino(tasmota open source)
* [CafePlugGuardian-ML](https://github.com/CAU-Capstone-PPL/CafePlugGuardian-ML)
    * AI model - pytorch, GRU model
* [CafePlugGuardian-ML_Server_Flask](https://github.com/CAU-Capstone-PPL/CafePlugGuardian-ML_Server_Flask)
    * AI server - flask

### Additional Requirements
* MongoDB
    * NoSQL DBMS
    * In our project, we install and use mongoDB on an ec2 instance.
    * Install and run mongoDB, or use a mongoDB server.
* MQTT Broker
    * In our project, we install and use mosquitto as an MQTT broker on an ec2 instance.
    * You can install another MQTT broker or use a separate broker server if you have one.

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
