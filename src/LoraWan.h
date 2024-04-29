
#pragma once

#include "LoraConfig.h"
#include "MKRWAN.h"
#include "Results.h"

class LoRaWAN
{
  public:
  void setup();
  void sendMsgMeasurements(const Results& results);
  void sendMsg(const String msg);

  private:
  String convertMeasurementsToString(const Results& results);
  LoRaModem loraModem; ///< LoRa modem
  const u_int16_t modemDealy = 1000; ///< delay for stable communication with modem, in ms
};
