
#include "LoRaWAN.h"
#include "DustbinConfig.h"

/**
 * @brief  setup and connect LoRa modem
 */
void LoRaWAN::setup()
{
  Serial.println("LoRaWAN setup");
  if (!loraModem.begin(EU868))
  {
    Serial.print("Failed to start LoRa module");
  };
  Serial.print("LoRa module start correct");

  int connected = 0;
  if (Config::auth == Authorization::OTAA)
  {
    connected = loraModem.joinOTAA(Config::APPEUI, Config::APPKEY, Config::DEVEUI);
  }
  else
  {
    connected = loraModem.joinABP(Config::DEVADR, Config::NWSKEY, Config::APPSKEY);
  }

  if (!connected)
  {
    Serial.print("Something went wrong with connect into LoRa gateway.");
  }

  if (Config::constDataRate)
  {
    loraModem.dataRate(0);
  }

  delay(modemDealy);
}

/**
 * @brief  Send measurements via LoRaWAN
 * @param  result: measurements to send
 */
void LoRaWAN::sendMsgMeasurements(const Results& result)
{
  String msg = convertMeasurementsToString(result);
  sendMsg(msg);
}

/**
 * @brief  Send message via LoRaWAN
 * @param  msg: message to send
 */
void LoRaWAN::sendMsg(const String msg)
{
  for (unsigned int i = 0; i < msg.length(); i++)
  {
    Serial.print(msg[i] >> 4, HEX);
    Serial.print(msg[i] & 0xF, HEX);
  }
  Serial.println();

  if (Config::constDataRate)
  {
    loraModem.dataRate(0);
    delay(modemDealy);
  }

  int err;
  loraModem.beginPacket();
  loraModem.print(msg);
  err = loraModem.endPacket(true);
  Serial.println(err);
  loraModem.sleep();
}

/**
 * @brief  Convert measurements to string, ready to send
 * @param  results: measurements to convert
 * @return assembled output string
 */
String LoRaWAN::convertMeasurementsToString(const Results& results)
{
  String msg;
  msg += "D" + String(DustbinConfig::deviceId);
  msg += "P" + String(results.dumpsterFilingPercentage) +"%";
  msg += "B" + String(results.batteryStatus);

  return msg;
}
