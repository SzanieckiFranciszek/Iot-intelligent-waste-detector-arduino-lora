#ifndef ULTRASONICSENSOR_H
#define ULTRASONICSENSOR_H

#include "Arduino.h"
#include "Ultrasonic.h"
class UltrasonicSensor {
public:
    UltrasonicSensor(int signalPin) 
        : signalPin(signalPin), ultrasonic(signalPin)
    {
        
    }

    void initSensor() {
        Serial.println("Ultrasonic Sensor init");
    }

    // Method to measure distance
    float measureDistance() {
        // Send a short pulse on the trigger pin
        Serial.println("Measuring in Progress");

        float distance = ultrasonic.MeasureInCentimeters();

        return distance;
    }

private:
    int signalPin;
    Ultrasonic ultrasonic;

};

#endif // ULTRASONICSENSOR_H
