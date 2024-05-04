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

     float measureBatteryStatusOnAnalogInput() {
        Serial.println("Measuring battery voltage in progress:");

        readAnalogValue = analogRead(analogMeasurePin);

        return readAnalogValue;
    }

     void printBatteryVoltage(float readValue) {
        Serial.println("Measured battery voltage: ");
        voltage = readValue * (3.3/1024.0);
        Serial.print(voltage);
    }

    int calculateBatteryStatusInPercentage() {
    float analogReadValue = measureBatteryStatusOnAnalogInput();
    printBatteryVoltage(analogReadValue);
    if (voltage >= 1024) {
        return 100; // 100% Battery Status
    } else if (voltage >= 972) {
        return 75; // 75% Battery Status
    } else if (voltage >= 921) {
        return 50; // 50% Battery Status
    } else if (voltage >= 901) {
        return 25; // 25% Battery Status
    } else if (voltage >= 870) {
        return 5; // 5% Battery Status
    } else {
        return 0; // Battery Status
    }
}

private:
    float analogMeasurePin;
    int readAnalogValue = 0;
    float voltage = 0;
};

#endif // BATTERY_H