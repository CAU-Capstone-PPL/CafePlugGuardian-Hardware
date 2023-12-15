# Changelog
<h4>Excluding the contents of tasmota open source, I only wrote the modification log of the CafePlugGuardian-Hardware project.</h4>

## [1.0.0]

### PlatformIO environment settings
#### Edit some .ini files and unset .gitignore
* In the tasmota open source original, only the sample.ini file is provided so that personal configuration files can be inserted, and the original has been processed with .gitignore, but the settings have been released and the modification details are shared.
    * platformio_override.ini
        * Comment out unnecessary libraries
        * I modified this file because I didn't know how to remove it only for specific environment settings, so it affects more than just the tasmota32-samplingCurrent setting.
        * Will be modified later if possible
    * platformio_tasmota_cenv.ini
        * Add tasmota32-samplingCurrent preference
#### Add TimerInterrupt_generic library
* Added to enable microsecond timer interrupts

### Edit user_config_override.h file
* Originally, .gitignore was processed, and there was a sample file instead, but .gitignore was processed and the folder was created.
* Create a rule that activates the MeasurePower command once every 5 seconds after booting.
* Currently, the rule set in user_config_override.h does not work immediately.
* If we find a way to activate it automatically without having to activate it manually, we will fix it.

### Implementing new features
* Add code for new features to file /tasmota/tasmota_xsns_sensor/xsns_02_analog.ino
    * xsns_02_analog.ino originally has codes for several analog sensors, and also supports CT Power sensors.
    * It seemed difficult to apply to acs712 and zmpt101b, so instead of using the existing code, a new implementation was implemented.
    * In the future, if we modify the existing code to use it or find a way to separate the files, we will consider doing so.
* Failed to link with tasmota's power measurement data variable and implemented a new one.
* Relay is relatively easy to integrate with tasmota's existing template, but due to time constraints, it cannot be integrated and must be implemented directly.

* **Add Features**
    1. Compensates the measurement results of ADC with poor precision of ESP32
    2. Convert measurements from the ACS712 sensor to current
    3. Convert measurements from Zmpt101b sensor to voltage
    4. Power measurement implementation
    5. Implementation of current and voltage sampling

* **Add Commands**
    1. TestCommand
        * Code for MQTT testing
        * Always returns the same json
    2. TestPower
        * Returns real measurement results, not measurements adjusted for error compensation
    3. CafePlugStatus
        * Return plug status
    4. MeasurePower
        * Power measurement function operation and plug status return
    5. CalSensitive
        * Error compensation through various types of sensitivity adjustments
        * ADC sensitivity, current sensor sensitivity, voltage sensor sensitivity
    6. PlugToggle
        * Plug toggle on, off
    7. SamplingCurrent
        * Current sampling 500 times at 0.5ms period
        * Supports multi-sampling and software low pass filter depending on option
    8. SamplingVoltage
        * Voltage sampling 500 times at 0.5ms period
        * Supports multi-sampling and software low pass filter depending on option