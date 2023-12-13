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

### Implementing new features