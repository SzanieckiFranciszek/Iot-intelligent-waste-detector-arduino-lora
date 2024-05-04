
#include "Measurements.h"
#include "LoraConfig.h"
#include "PinConfig.h"
#include "UltrasonicSensor.h"
#include "Arduino.h"
#include "DustbinConfig.h"
#include "algorithm"
#include "Battery.h"

Measurements::Measurements(): 
ultrasonicSensor(UltrasonicSensor(Pins::ultrasonicTriggerPin, Pins::ultrasonicEchoPin)),
battery(Battery(Pins::batteryVoltagePin))
{}

void Measurements::init_sensors()
{
  ultrasonicSensor.initSensor();
  battery.initMeasure();
}

void Measurements::measure(Results& results)
{
  results.dumpsterFilingPercentage = getDumpsterFilingPercentage();
  results.batteryStatus = getBatteryStatus();
}

int Measurements::getUltrasonicDistance()
{
  return ultrasonicSensor.measureDistance();
}

String Measurements::getBatteryStatus()
{
  return String(battery.calculateBatteryStatusInPercentage());
}


int Measurements::getDumpsterFilingPercentage()
{
    ultrasonicDistance = getUltrasonicDistance();
    Serial.print("Height of the dustbin in centimeters: ");
    Serial.print(ultrasonicDistance);
    Serial.print("Filling of the dustbin in percentage: ");
    heightDustbin = DustbinConfig::heightDustbinInCentimeters;

    int fillingPercentage =  (1 - ((float)ultrasonicDistance / heightDustbin)) * 100;
    fillingPercentage = std::max(0, std::min(fillingPercentage, 100));
    Serial.print(fillingPercentage);
    
    return fillingPercentage;
}



