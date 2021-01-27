/*
 * Author: Enrico Bagattin
 * 
 * This library reads barcodes from a scanner (UART communication)
 * 
 * Connection is made through the Serial1 of Arduino Mega 2560:
 *
 *  Arduino PIN 18 (RX1)   =======  5v to 3.3v logic converter ======= GROW GM73 Barcode Scanner TX (black wire)
 *  Arduino PIN 19 (TX1)   =======  5v to 3.3v logic converter ======= GROW GM73 Barcode Scanner RX (yellow wire)
 * 
 * Ensure to scan UART Output QR from the manual to use the barcode scanner
*/

#include "BarcodeScanner.h"

std::string inputString = "";
std::string resultingBCode = "";
boolean stringComplete = false;
int countstr = 0;
unsigned long millisendstr = 0;

void initialize_barcode() {
    inputString.reserve(50);
    Serial1.begin(9600);
}

void serial_barcode_event() {
    if (Serial1.available() > 0) {
        // Get the new byte:
        char inChar = (char)Serial1.read();
        // Add it to the inputString:
        inputString += inChar;
        countstr++;
        millisendstr = millis();
    } else {
        if (millis() - millisendstr > 1000 && countstr > 0) {
            stringComplete = true;
        }
    }
}

bool isNotAlnum(char c) {
    return isalnum(c) == 0;
}

std::string get_barcode_input() {
    resultingBCode = "";

    serial_barcode_event();
    if (stringComplete) {
        resultingBCode = inputString;
        // Remove non alphanumeric chars
        resultingBCode.erase(std::remove_if(resultingBCode.begin(), resultingBCode.end(), isNotAlnum), resultingBCode.end());
        inputString = "";
        stringComplete = false;
        countstr = 0;
    }

    return resultingBCode;
}