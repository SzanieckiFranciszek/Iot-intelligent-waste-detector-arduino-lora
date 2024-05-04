
#include "Arduino.h"

#pragma once

enum class Authorization
{
  OTAA,
  ABP
};

namespace Config
{
const Authorization auth = Authorization::OTAA; ///< LoRaWAN authorization method, ABP or OTAA

/*OTAA credential*/
const String DEVEUI = "A8610A35392C6B05"; ///< Device EUI
const String APPEUI = "0000000000000000"; ///< Application EUI
const String APPKEY = "D2E67F9486F01D0720E9F1728CFC995A"; ///< Application key

/*ABP credential*/
const String DEVADR = "260B9FB5"; ///< Device adress
const String NWSKEY = "5B600EF32797FC5BB3D6B39D389FE103"; ///< Network session key
const String APPSKEY = "7A44FD75152EA3A985784FF3ED219786"; ///< Application session key

const uint8_t uplinkPort = 1; ///< Port for uplink
// const uint16_t sleepTime = 36000; ///< Uplink interval in miliseconds
const uint16_t sleepTime = 10000; ///< Uplink interval in miliseconds
const bool constDataRate = true;
} // namespace Config
