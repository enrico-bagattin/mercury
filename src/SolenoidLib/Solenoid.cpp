/*
 * Author: Enrico Bagattin
 * 
 * This library manage a solenoid through a relay
 * 
 * Connection diagram:
 *  Arduino PIN 2   ===================  Buzzer
 *  Arduino PIN 3   ===================  Relay
 *  Arduino PIN 4   ===================  Red led
 *  Arduino PIN 5   ===================  Green led
*/

#include "Solenoid.h"

void initialize_solenoid() {
    pinMode(LED_G, OUTPUT);
    pinMode(LED_R, OUTPUT);
    pinMode(RELAY, OUTPUT);
    pinMode(BUZZER, OUTPUT);
    noTone(BUZZER);
    digitalWrite(RELAY, LOW);
}

void open_lock() {
    delay(100);
    digitalWrite(RELAY, HIGH);
    digitalWrite(LED_G, HIGH);
    delay(ACCESS_DELAY);
    digitalWrite(RELAY, LOW);
    digitalWrite(LED_G, LOW);
}

void denied_access() {
    digitalWrite(LED_R, HIGH);
    tone(BUZZER, 300);
    delay(DENIED_DELAY);
    digitalWrite(LED_R, LOW);
    noTone(BUZZER);
}

void accessControl(bool valid) {
    if (valid) {
        Serial.println("Authorized access");
        Serial.println();
        open_lock();
    } else {
        Serial.println("Access denied");
        denied_access();
    }
}