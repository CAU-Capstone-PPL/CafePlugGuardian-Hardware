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
<img width="80%" src="https://github.com/CAU-Capstone-PPL/CafePlugGuardian-Server/assets/55429793/74940115-831a-49f7-ab9a-3d5dc402089a"/>

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

### Change Log
* [ChangeLog](./CHANGELOG.md)
* Excluding the contents of tasmota open source, I only wrote the modification log of the CafePlugGuardian-Hardware project.

### How to use CafePlugGuardian-Hardware
* Require Hardware
    * esp32
        * Main micro control unit
        * In our project, we used the lolin d32 pro development board, but it doesn't matter as long as it is an esp32.
        * To use the esp8266, you need to modify the code, and since there is only one ADC, analog measurement of voltage is impossible, so you need to find another method.
    * ACS712
        * current sensor
        * There are 5A, 20A, and 30A models. Use the appropriate model.
        * In our project, the current of the measurement target is generally less than 1A, so we used the 5A model.
    * Zmpt101b
        * voltage sensor
    * Resistance
        * Used for voltage distribution and RC low pass filter.
    * Capacitor
        * Used for RC low pass filter.

* Circuit Design
    * **This circuit may be inaccurate as it was created by a computer engineering student with limited circuit knowledge.**

        <img width="80%" src="https://github.com/CAU-Capstone-PPL/CafePlugGuardian-Server/assets/55429793/bb297a10-9cf0-49ef-acb7-77a32b713c51"/>
     
    * Power Supply
        * Supplying 5v power through USB has a lot of noise, so supply power through a 5.5mm barrel jack, which is a little cleaner.
        * The esp32 development board I have does not have a 5.5mm port, so I supply power through Arduino Uno instead.
        * If there is another way to supply clean power, it is recommended to supply it instead of Arduino Uno.
    * Current Measurement Circuit
        * Since esp32 is 3.3v based, it is dangerous to receive the 5v signal from ACS712 as is, so the voltage is distributed using 5k ohm and 10k ohm resistors.
            * The minimum value of Output Resistive Load of the ACS712 sensor is 4.7k ohm, so set R1 to 5k ohm, which is larger than that.
            * I don't know if this is correct due to my lack of circuit knowledge, but when dividing the voltage between 1k ohm and 2k ohm, it was not distributed properly.
        * Implement RC low pass filter with 5k ohm resistor and 10nF capacitor.
            * The ACS712 sensor module itself has an RC filter implemented, and I understand that the capacitor capacity is different for each module (not sure), but the cutoff frequency is usually very high due to the small capacity.
            * Since I don't know how to solder, I implemented a filter on the output signal, but if you can solder, I recommend connecting a 100nF capacitor to the filter part of the module.
            * The larger the capacity of the capacitor, the lower the cutoff frequency of the low pass filter, so noise is reduced, but precise patterns may disappear, so an appropriate value must be found.
    * Voltage Measurement Circuit
        * When 3.3v is supplied to the voltage sensor's VCC, measurement results of 0 to 3.3v are automatically output.
        * Implement RC low pass filter with 10k ohm resistor and 100nF capacitor.

* Build and Upload
    1. Use PlatformIO
        * Install PlatfromIO in vscode
    2. Change project environment settings
        * tasmota32-samplingCurrent
    3. User Config Settings
        * Edit /tasmota/user_config_override.h file
        * Modify the MQTT_HOST preprocessor to register the address of the MQTT broker you will use.
        * Wi-Fi SSID and password can be set in advance to connect in a similar way
        * It is not a required task, and can be added on the tasmota web page after uploading.
    4. Build
    5. Upload
        * After building, connect esp32 to UART and upload by pressing the upload button.
        * If you have a device that already has Tasmota installed, you can upload the built firmware from the tasmota web page.
            * However, in this case, changes to user_config_override.h are not reflected.
            * Edit it directly on the web page, or go into the console and use the reset command.
                * Different reset functions are performed depending on the option, so refer to the reset command description in the following link.
                * https://tasmota.github.io/docs/Commands/#management
                * reset 5: Reset while maintaining Wi-Fi settings
                * reset 6: Reset while maintaining Wi-Fi and MQTT
    6. Rule activation
        * Currently, the rule set in user_config_override.h does not work immediately.
        * You must enter the console and activate the rule with the following command.
        * Rule1 1
        * Reboot the plug after activating the rule.
        * If we find a way to activate it automatically without having to activate it manually, we will fix it.

* How to use Smart Plug
    * [CafePlugGuardian-Client](https://github.com/CAU-Capstone-PPL/CafePlugGuardian-Client)
        * User app project by CafePlugGuardian.
        * Basically, the app provides a manual and sets it automatically.
        * If you have a problem with the app, you can follow tasmota's basic method as described below, but you cannot use CafePlugGuardian's services.
    * Tasmota Basic Method
        * If you don't have Wi-Fi set up, the plug creates a hotspot.
        * After connecting to the hotspot, go to 192.168.4.1 and access the plug settings web page.
        * Enter the Wi-Fi SSID and password to connect and wait for it to reboot.
        * After that, you can access the management page using the IP address assigned to the plug (by connecting to the same Wi-Fi as the plug).

## License
This program is licensed under GPL-3.0
