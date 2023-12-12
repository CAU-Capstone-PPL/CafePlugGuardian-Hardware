#ifndef _USER_CONFIG_OVERRIDE_H_
#define _USER_CONFIG_OVERRIDE_H_

#ifdef FIRMWARE_SAMPLINGCURRENT
// -- MQTT ----------------------------------------
  #ifdef  MQTT_HOST
    #undef  MQTT_HOST
  #endif
  #define MQTT_HOST         ""                // [MqttHost]

  #ifdef  MQTT_PORT
    #undef  MQTT_PORT
  #endif
  #define MQTT_PORT         1883

// -- MQTT - Telemetry ----------------------------
  #ifdef  TELE_PERIOD
    #undef  TELE_PERIOD
  #endif
  #define TELE_PERIOD       0               // [TelePeriod] Telemetry (0 = disable, 10 - 3600 seconds)

// -- Rules or Script  ----------------------------
  #define USE_RULES                                // Add support for rules (+8k code)
    #define USE_EXPRESSION                         // Add support for expression evaluation in rules (+3k2 code, +64 bytes mem)
      #define SUPPORT_IF_STATEMENT

  #ifdef  USER_RULE1
    #undef USER_RULE1
  #endif
  #define USER_RULE1 "ON system#boot DO RuleTimer1 5 ENDON ON Rules#Timer=1 DO Backlog publish cmnd/%%topic%%/MeasurePower; RuleTimer1 5 ENDON"

  #ifdef  USE_ADC
    #undef USE_ADC
  #endif
  #define USE_ADC
#endif

#endif  // _USER_CONFIG_OVERRIDE_H_
