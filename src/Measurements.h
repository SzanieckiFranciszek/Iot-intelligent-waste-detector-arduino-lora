
#pragma once

#include "PinConfig.h"
#include "Results.h"
#include "UltrasonicSensor.h"
#include "Battery.h"



class Measurements
{
  public:
  Measurements();
  void initSensors();
  void measure(Results& results);
  UltrasonicSensor ultrasonicSensor;
  Battery battery;  

  private:
  int getUltrasonicDistance();
  int getDumpsterFilingPercentage();
  String getBatteryStatus();
  int ultrasonicDistance;
  int heightDustbin;
};