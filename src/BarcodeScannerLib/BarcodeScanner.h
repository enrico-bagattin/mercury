/*
 * Author: Enrico Bagattin
 * 
 * This library reads barcodes from a scanner (UART communication)
 * 
 * Connection is made through the Serial1 of Arduino Mega 2560:
 *
 *  Arduino PIN 18 (RX1)   =======  5v to 3.3v logic converter ======= GROW GM73 Barcode Scanner TX (black wire)
 *  Arduino PIN 19 (TX1)   =======  5v to 3.3v logic converter ======= GROW GM73 Barcode Scanner RX (yellow wire)
*/

#include <Arduino.h>
#include <wiring_private.h>
#include "ArduinoSTL.h"

void initialize_barcode();
void serial_barcode_event();
std::string get_barcode_input();