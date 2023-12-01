#ifndef _USER_CONFIG_OVERRIDE_H_
#define _USER_CONFIG_OVERRIDE_H_

#ifdef FIRMWARE_SAMPLINGCURRENT
//  #undef  USER_TEMPLATE
//  #define USER_TEMPLATE "{\"NAME\":\"SamplingCurrent\",\"GPIO\":[0,0,0,3104,0,32,0,0,224,576,0,0,0,0],\"FLAG\":0,\"BASE\":18}"

// -- MQTT ----------------------------------------
  #undef  MQTT_HOST
  #define MQTT_HOST         ""                // [MqttHost]

  #undef  MQTT_PORT
  #define MQTT_PORT         1883

// -- MQTT - Telemetry ----------------------------
  #undef  TELE_PERIOD
  #define TELE_PERIOD       0               // [TelePeriod] Telemetry (0 = disable, 10 - 3600 seconds)
#endif

#endif  // _USER_CONFIG_OVERRIDE_H_