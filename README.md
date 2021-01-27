# Arduino Parcel Delivery Project

## Development Env
- Install the lastest version of Arduino IDE
- Optional: install VS Code with the Arduino plug-in (Settings are searchable through `Cmd+Shift+P` or `Ctrl+Shift+P`)


## Node MCU ESP12E v2 Config

Open Arduino IDE > Preferences > additional boards manager > `http://arduino.esp8266.com/stable/package_esp8266com_index.json` then install esp8266 in boards manager

Open VS Code Cmd+Shift+P > Board Manager > Additional URLs > Edit in settings.json 
```
{
    "arduino.path": "/Applications",
    "arduino.additionalUrls": "http://arduino.esp8266.com/stable/package_esp8266com_index.json",
    "arduino.defaultBaudRate": 9600,
    "C_Cpp.updateChannel": "Insiders",
    "C_Cpp.intelliSenseEngine": "Tag Parser"
}
```

To use this board: 
- Board Configuration: select `NodeMCU ESP-12E`
- Baud Rate set to `9600`


## Test Boards
Use `Select Serial Port` to check the correct port
Boards can be tested using `HelloArduino` and `BlinkNodeMCU` ino files placed into Setup folder
Use `Open Serial Monitor` to see data
Use `Arduino: Upload` to upload sketches

## Libraries and Boards
Accessible through Arduino Library Manager
- ArduinoSTL
- Arduino AVR Boards 1.8.2 (NO 1.8.3)

## Problems on MAC OS
pyserial or esptool directories not found next to this upload.py tool. => https://forum.arduino.cc/index.php?topic=702144.msg4793318#msg4793318