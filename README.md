Nara-Bot
========

An Arduino controlled Robot.

*These sketches are designed for an Arduino Mega 2560. Sketches have currently only been tested on Processing 3.11/Arduino 15, OS X 10.11.5 (15F34)*


Parts used in this robot: 

1× Pololu Qik 2s12v10 Motor Driver
http://www.pololu.com/product/1112

1× Dagu Wild Thumper 4WD All-Terrain Chassis, Silver, 75:1
http://www.pololu.com/product/1565

1× Arduino Mega 2560
https://www.arduino.cc/en/Main/ArduinoBoardMega2560

1× xBee Shield
https://www.sparkfun.com/products/10854

1× xBee Explorer Dongle
https://www.sparkfun.com/products/9819

2× xBee Pro
https://www.sparkfun.com/products/8742

1× Venom 11.1v Li Po Battery
http://smile.amazon.com/gp/product/B000W7PZU6/ref=wms_ohs_product?ie=UTF8&psc=1

1x Xbox One Controller
http://smile.amazon.com/Xbox-One-Wireless-Controller/dp/B00YJJ0OQS/ref=sr_1_3?s=videogames&ie=UTF8&qid=1465081409&sr=1-3&keywords=Xbox+One+Controller

(Optional)
Non Computer based host(Arduino Gamepad) (WIP)
1x Arduino Nano

Arduino Libraries: 
-Pololu Qik library
https://github.com/pololu/qik-arduino

Processing: 
-Game Control Plus
-G4P

Important files:
-Readme.md (You're reading it!)

Libraries->
	PololuQik : Current version last verified working if future changes occur in the master branch.

Narabot->
	-NaraBot.ino : This is the Arduino Mega 2560 code for the bot itself.

NaraPad->
	-NaraPad.ino : This is standalone Arduino controlpad code for use without a computer host.

Transmitter->
	-Transmitter.ino : This is the Processing code to utilize the xBee and Xbox gamepad via USB.

	-joypadconfig : This is the configuration file to allow Processing to identify controller buttons (Default: Xbox One controller) If you are using a different controller, use the configurator example sketch in G4P to generate a new configuration.

