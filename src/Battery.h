#ifndef BATTERY_H
#define BATTERY_H

#include "Arduino.h"

class Battery {
public:
    Battery(float analogPin) 
        : analogMeasurePin(analogPin)
    {}

    void initMeasure() {
        Serial.println("Battery voltage measuring init");
        pinMode(analogMeasurePin, INPUT);
    }

     float measureBatteryVoltageOnAnalogInput() {
        Serial.print("Measuring battery voltage in progress:");

        readAnalogValue = analogRead(analogMeasurePin);

        mesuredVoltage = readAnalogValue * (3.3/1024.0);
        realInputVoltage =  mesuredVoltage * ((resistorOne + resistorTwo) / resistorTwo); //Real battery voltage without voltage divider
        
        return realInputVoltage;
    }

     void printBatteryVoltage(float voltage) {
        Serial.println("Measured battery voltage: ");
        Serial.println(voltage);
        Serial.println(" V");
    }

    int calculateBatteryStatusInPercentage() {
    float batteryVoltage = measureBatteryVoltageOnAnalogInput();

    printBatteryVoltage(batteryVoltage);

    if (batteryVoltage >= 4.15) { // Max battery voltage = 4.2 V
        batteryPercentage = 100; // 100% Battery Status
    } else if (batteryVoltage >= 4.00 && batteryVoltage < 4.10) {
        batteryPercentage = 75; // 75% Battery Status
    } else if (batteryVoltage >= 3.80 && batteryVoltage < 4.00) {
        batteryPercentage = 50; // 50% Battery Status
    } else if (batteryVoltage >= 3.70 && batteryVoltage < 3.80) {
        batteryPercentage = 25; // 25% Battery Status
    } else if (batteryVoltage >= 3.60 && batteryVoltage < 3.70) {
        batteryPercentage = 5; // 5% Battery Status
    }
    Serial.print("Battery status: ");
    Serial.println(batteryPercentage);
    Serial.println(" %");
    return batteryPercentage;
}

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