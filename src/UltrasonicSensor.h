#ifndef ULTRASONICSENSOR_H
#define ULTRASONICSENSOR_H

#include <Arduino.h>

class UltrasonicSensor {
public:
    UltrasonicSensor(int triggerPin, int echoPin) 
        : m_triggerPin(triggerPin), m_echoPin(echoPin) 
    {}

    void initSensor() {
        Serial.println("Ultrasonic sensor init");
        pinMode(m_triggerPin, OUTPUT);
        pinMode(m_echoPin, INPUT);
    }

    // Method to measure distance
    float measureDistance() {
        // Send a short pulse on the trigger pin
        Serial.println("Measuring in Progress");
        digitalWrite(m_triggerPin, LOW);
        delayMicroseconds(2);
        digitalWrite(m_triggerPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(m_triggerPin, LOW);

        // Measure the time for the echo
        float duration = pulseIn(m_echoPin, HIGH);

        // Calculate the distance in cm
        float distance = duration * 0.034 / 2;

        Serial.print("Distance: ");
        Serial.println(distance);
        return distance;
    }

private:
    int m_triggerPin;
    int m_echoPin;
};

#endif // ULTRASONICSENSOR_H
