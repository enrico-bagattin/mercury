#include "src/MatrixKeyPadLib/MatrixKeyPad.h"

void setup() {
    initialize_keypad();  // "1234", "1256"
    Serial.begin(9600);
}

void loop() {
    verify_keypad_input();
}