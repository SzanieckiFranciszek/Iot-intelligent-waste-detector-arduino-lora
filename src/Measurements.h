
#pragma once

#include "PinConfig.h"
#include "Results.h"
#include "UltrasonicSensor.h"



class Measurements
{
  public:
  Measurements();
  void init_sensors();
  void measure(Results& results);
  UltrasonicSensor ultrasonicSensor;

  private:
  int getUltrasonicDistance();
  int getDumpsterFilingPercentage();
  void batteryMeasurmentInit();
  String getBatteryStatus();
  // String getValueFromJsonConfigFile(String key, String filePath);
  int ultrasonicDistance;
  int heightDustbin;
};