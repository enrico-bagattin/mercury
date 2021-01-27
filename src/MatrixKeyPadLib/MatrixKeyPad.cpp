/*
 * Author: Enrico Bagattin
 * 
 * This library checks the keypad input
 * 
 * Connection diagram for keypad pins:
 *  Arduino PIN 33   ===================  Matrix keypad 1
 *  Arduino PIN 35   ===================  Matrix keypad 2
 *  Arduino PIN 37   ===================  Matrix keypad 3
 *  Arduino PIN 39   ===================  Matrix keypad 4
 *  Arduino PIN 41   ===================  Matrix keypad 5
 *  Arduino PIN 43   ===================  Matrix keypad 6
 *  Arduino PIN 45   ===================  Matrix keypad 7
 *  Arduino PIN 47   ===================  Matrix keypad 8
*/

#include "MatrixKeyPad.h"

bool in_array(const std::string &value, const std::vector<std::string> &array) {
    return std::find(array.begin(), array.end(), value) != array.end();
}

void initialize_keypad() {
    int i;
    for (i = 0; i < ROWS; i++) {
        pinMode(rowMatrixPins[i], OUTPUT);
        pinMode(colMatrixPins[i], OUTPUT);
    }
}

void verify_keypad_input() {
    char customKey = customKeypad.getKey();
    if (customKey) {
        inputPin += customKey;
    }
    if (inputPin.length() == 4) {
        bool correct = in_array(inputPin, correctPins);
        std::cout << inputPin + ((correct) ? " Correct" : " Wrong") << "\n";
        inputPin = "";
    }
}