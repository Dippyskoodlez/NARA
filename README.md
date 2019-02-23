# Nara-Bot

An Arduino controlled Robot. Primary implementation is a computer host and Xbox One controller utilizing a Processing sketch for communication via Xbee to the remote Arduino driving a Pololu Qik 12v10 motor driver.

## Hardware

* [Arduino Mega 2560](https://store.arduino.cc/usa/arduino-mega-2560-rev3)

* [Pololu Qik 2s12v10 Dual Serial Motor Controller](https://www.pololu.com/product/1112)

* [xBee Xplorer Dongle](https://www.sparkfun.com/products/11697)

* [xBee Shield](https://www.sparkfun.com/products/12847)

* [2x Xbee](https://www.sparkfun.com/products/8742)

* [Dagu Wild Thumper 4 wheel 75:1 Chassis](https://www.pololu.com/product/1567)

* [Venom 20C 3S 5400mAh 11.1 LiPO Battery](https://smile.amazon.com/gp/product/B000W7PZU6/)

## Software Required

* Arduino IDE/Compatible
* Processing 3+

### Arduino Libraries

* [Pololu Qik library](https://github.com/pololu/qik-arduino)

### Processing Libraries

* [Game Control Plus](http://lagers.org.uk/gamecontrol/)

* [G4P](http://www.lagers.org.uk/g4p/)

## Files included

* Readme.md (You're reading it)

### Libraries

* PololuQik : Current version last verified working if future changes occur in the master branch.

### Narabot

* NaraBot.ino : This is the Arduino Mega 2560 code for the bot itself.

### NaraPad

* NaraPad.ino : This is standalone Arduino controlpad code for use without a computer host.

### Transmitter

* Transmitter.ino : This is the Processing code to utilize the xBee and Xbox gamepad via USB.

* joypadconfig : This is the configuration file to allow Processing to identify controller buttons (Default: Xbox One controller) If you are using a different controller, use the configurator example sketch in G4P to generate a new configuration.

## TODO

## Software additions/reworks

* Joypadconfig updates for Xbox and Switch Pro Controller

* Hardware for NaraPad.

## Hardware related additions

* Schematics/Wiring Diagrams
