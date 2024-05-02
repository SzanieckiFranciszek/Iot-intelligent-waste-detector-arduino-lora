
#include "Measurements.h"

#include "LoraConfig.h"
#include "PinConfig.h"
#include "UltrasonicSensor.h"
#include <Arduino.h>
#include <DustbinConfig.h>
#include <algorithm>

Measurements::Measurements(): 
ultrasonicSensor(UltrasonicSensor(Pins::ultrasonicTriggerPin, Pins::ultrasonicEchoPin))
{}

void Measurements::init_sensors()
{
  ultrasonicSensor.initSensor();
  // batteryMeasurmentInit();
  
}

void Measurements::measure(Results& results)
{
  results.dumpsterFilingPercentage = getDumpsterFilingPercentage();
  results.batteryStatus = getBatteryStatus();
}

// {
//   // pinMode(Pins::batteryVoltagePin, INPUT);
// }

int Measurements::getUltrasonicDistance()
{
  return ultrasonicSensor.measureDistance();
}

String Measurements::getBatteryStatus()
{
  // if else here
  return "OK";
}


int Measurements::getDumpsterFilingPercentage()
{
    ultrasonicDistance = getUltrasonicDistance();
    Serial.print("Height of the dustbin in centimeters: ");
    Serial.println(ultrasonicDistance);
    Serial.print("Filling of the dustbin in percentage: ");
    heightDustbin = DustbinConfig::heightDustbinInCentimeters;

    int fillingPercentage =  (1 - ((float)ultrasonicDistance / heightDustbin)) * 100;
    fillingPercentage = std::max(0, std::min(fillingPercentage, 100)); // ogranicz wartość do zakresu 0-100
    Serial.println(fillingPercentage);
    
    return fillingPercentage;
}



