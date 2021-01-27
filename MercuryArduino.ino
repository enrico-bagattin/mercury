/*
 * Author: Enrico Bagattin
 * 
 * Main
 * 
*/

#include "src/SolenoidLib/Solenoid.h"
#include "src/MatrixKeyPadLib/MatrixKeyPad.h"
#include "src/BarcodeScannerLib/BarcodeScanner.h"
#include "ArduinoSTL.h"

const std::vector<std::string> correctPins     {"1234", "1256"};
const std::vector<std::string> correctBarcodes {"BA0226793241", "L1204157681014V5"};

std::string k_code = "";
std::string b_code = "";

bool in_array(const std::string &value, const std::vector<std::string> &array) {
    return std::find(array.begin(), array.end(), value) != array.end();
}

void verify_code(const std::string &code, const std::vector<std::string> &valids) {
    if (code.length() > 0) {
        bool valid = in_array(code, valids);
        std::cout << code + ((valid) ? " Correct" : " Wrong") << "\n";
        accessControl(valid);
    }
}

void setup() {
    initialize_solenoid();
    initialize_keypad();
    initialize_barcode();
    Serial.begin(9600);
}

void loop() {
    k_code = get_keypad_input();
    verify_code(k_code, correctPins);

    b_code = get_barcode_input();
    verify_code(b_code, correctBarcodes);
}