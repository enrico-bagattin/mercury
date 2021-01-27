#include "src/SolenoidLib/Solenoid.h"
#include "src/MatrixKeyPadLib/MatrixKeyPad.h"
#include "src/BarcodeScannerLib/BarcodeScanner.h"

void setup() {
    initialize_solenoid();
    initialize_keypad();  // "1234", "1256"
    initialize_barcode();
    Serial.begin(9600);
}

void loop() {
    get_keypad_input();
    get_barcode_input();
}