/*
 * Author: Enrico Bagattin
 * 
 * This library manage a solenoid through a relay
 * 
 * Connection diagram for keypad pins:
 *  Arduino PIN 2   ===================  Buzzer
 *  Arduino PIN 3   ===================  Relay
 *  Arduino PIN 4   ===================  Red led
 *  Arduino PIN 5   ===================  Green led
*/

#define LED_G 5
#define LED_R 4
#define RELAY 3
#define BUZZER 2
#define ACCESS_DELAY 800
#define DENIED_DELAY 1000

void initialize_solenoid();
void open_lock()
void denied_access();
void accessControl(bool valid);