
#include "ArduinoLowPower.h"
#include "LoraConfig.h"
#include "LoRaWAN.h"
#include "Measurements.h"
#include "PinConfig.h"
#include "Results.h"
#include <Arduino.h>

Measurements measurements;
LoRaWAN loraWan;
Results results;

void setup()
{
  Serial.begin(9600);
  // delay(60000); // TODO: test without this

  loraWan.setup();
  measurements.init_sensors();
}

void loop()
{
  measurements.measure(results);
  loraWan.sendMsgMeasurements(results);
  Serial.println("Deep sleep started");
  delay(120000);
  // LowPower.deepSleep(120000);
  //set up deepslep.
  Serial.println("Deep sleep ended");
}
