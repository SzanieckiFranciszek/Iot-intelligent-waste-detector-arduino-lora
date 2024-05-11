
#include "ArduinoLowPower.h"
#include "LoraConfig.h"
#include "LoRaWAN.h"
#include "Measurements.h"
#include "PinConfig.h"
#include "Results.h"
#include <Arduino.h>
#include <Led.h>

Measurements measurements;
LoRaWAN loraWan;
Results results;


void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  signalizeStartDevice();
  delay(120000); // TODO: test without this
  loraWan.setup();
  measurements.initSensors();

}

void loop()
{
  measurements.measure(results);
  loraWan.sendMsgMeasurements(results);
  Serial.println("Arduino deep sleep started");
  // delay(14400000);
  // LowPower.deepSleep(43200000);  // 43200000 = 12h
  signalizeCorrectSendDataViaLoraWan();
  LowPower.deepSleep(120000); // 60000 = 60s
  Serial.println("Arduino deep sleep ended");
}
