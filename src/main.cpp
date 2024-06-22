
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
  // delay(180000); // TODO: test without this
  delay(60000);
  loraWan.setup();
  measurements.initSensors();

}

void loop()
{
  measurements.measure(results);
  loraWan.sendMsgMeasurements(results);
  Serial.println("Arduino deep sleep started");
  signalizeCorrectSendDataViaLoraWan();
  // LowPower.deepSleep(14400000);  // 14400000 = 4h
  LowPower.deepSleep(120000); // 120000 = 120s = 2min
  Serial.println("Arduino deep sleep ended");
}
