#ifndef BATTERY_H
#define BATTERY_H

#include "Arduino.h"

class Battery {
public:
    Battery(float analogPin);

    void initMeasure();
    float measureBatteryVoltageOnAnalogInput();
    void printBatteryVoltage(float voltage);
    int calculateBatteryStatusInPercentage();

private:
    float analogMeasurePin;
    int readAnalogValue = 0;
    float mesuredVoltage = 0;
    float realInputVoltage = 0;
    float resistorOne = 10000;
    float resistorTwo = 22000;
    int batteryPercentage = 0;
};

#endif // BATTERY_H