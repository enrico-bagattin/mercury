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

#include "Keypad.h"
#include "ArduinoSTL.h"
#include <vector>

#define ROW_1 33
#define ROW_2 35
#define ROW_3 37
#define ROW_4 39
#define COL_1 41
#define COL_2 43
#define COL_3 45
#define COL_4 47

const byte ROWS = 4;  //four rows
const byte COLS = 4;  //four columns
inline std::string inputPin = "";

const char hexaKeys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};
//connect to the row pinouts of the keypad
const byte rowMatrixPins[ROWS] = {ROW_1, ROW_2, ROW_3, ROW_4};
//connect to the column pinouts of the keypad
const byte colMatrixPins[COLS] = {COL_1, COL_2, COL_3, COL_4};

const std::vector<std::string> correctPins {"1234", "1256"};

const Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowMatrixPins, colMatrixPins, ROWS, COLS);

bool in_array(const std::string &value, const std::vector<std::string> &array);

void initialize_keypad();

void verify_keypad_input();