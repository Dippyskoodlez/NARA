# Nara-Bot

An Arduino controlled Robot. Primary implementation is a computer host and Xbox One controller utilizing a Processing sketch for communication via Xbee to the remote Arduino driving a Pololu Qik 12v10 motor driver.

* These sketches are designed for an Arduino Mega 2560. *

## Software Required

* Arduino IDE/Compatible
* Processing 3.x

### Arduino Libraries used

* [Pololu Qik library](https://github.com/pololu/qik-arduino)

### Processing

* [Game Control Plus](http://lagers.org.uk/gamecontrol/)

* [G4P](http://www.lagers.org.uk/g4p/)

## Files included

* Readme.md (You're reading it!)

### Libraries

* PololuQik : Current version last verified working if future changes occur in the master branch.

### Narabot

* NaraBot.ino : This is the Arduino Mega 2560 code for the bot itself.

### NaraPad

* NaraPad.ino : This is standalone Arduino controlpad code for use without a computer host.

### Transmitter

* Transmitter.ino : This is the Processing code to utilize the xBee and Xbox gamepad via USB.

* joypadconfig : This is the configuration file to allow Processing to identify controller buttons (Default: Xbox One controller) If you are using a different controller, use the configurator example sketch in G4P to generate a new configuration.